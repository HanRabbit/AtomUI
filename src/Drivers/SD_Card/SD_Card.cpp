#include "SD_Card.h"
#include "Common/Log/Log.h"

void *sd_open_cb(lv_fs_drv_t *drv, const char *path, lv_fs_mode_t mode);
lv_fs_res_t sd_close_cb(lv_fs_drv_t *drv, void *file_p);
lv_fs_res_t sd_read_cb(lv_fs_drv_t *drv, void *file_p, void *buf, uint32_t btr, uint32_t *br);
lv_fs_res_t sd_write_cb(lv_fs_drv_t *drv, void *file_p, const void *buf, uint32_t btw, uint32_t *bw);
lv_fs_res_t sd_seek_cb(lv_fs_drv_t *drv, void *file_p, uint32_t pos, lv_fs_whence_t whence);
lv_fs_res_t sd_tell_cb(lv_fs_drv_t *drv, void *file_p, uint32_t *pos_p);

void *sd_dir_open_cb(lv_fs_drv_t *drv, const char *path);
lv_fs_res_t sd_dir_read_cb(lv_fs_drv_t *drv, void *rddir_p, char *fn, uint32_t fn_len);
lv_fs_res_t sd_dir_close_cb(lv_fs_drv_t *drv, void *rddir_p);

/* SD 卡初始化 */
void SD_Card::init() {
    lv_fs_drv_t fs_drv;
    lv_fs_drv_init(&fs_drv);

    /* 设置 SD 卡引脚 */
    SD_MMC.setPins(SD_CLK, SD_CMD, SD_DATA0, SD_DATA1, SD_DATA2, SD_DATA3);

    /* 使用 4 bit MMC 模式挂载 SD 卡 */
    update_status();

    /* 使用在 lv_conf.h 中的盘符 */
    fs_drv.letter = LV_FS_FATFS_LETTER;

    fs_drv.open_cb = sd_open_cb;
    fs_drv.close_cb = sd_close_cb;
    fs_drv.read_cb = sd_read_cb;
    fs_drv.write_cb = sd_write_cb;
    fs_drv.seek_cb = sd_seek_cb;
    fs_drv.tell_cb = sd_tell_cb;
    fs_drv.dir_open_cb = sd_dir_open_cb;
    fs_drv.dir_read_cb = sd_dir_read_cb;
    fs_drv.dir_close_cb = sd_dir_close_cb;

    fs_drv.user_data = nullptr;

    /* 注册文件系统 */
    lv_fs_drv_register(&fs_drv);

    /* 如果 lv_fs_fatfs.c 报错，将 DIR 更改为 FF_DIR */

    /* 设置定时器刷新状态 */
    Timer_Manager.t_register([] (lv_timer_t *timer) {
        /* 通过 lambda 表达式捕获 this 指针，在 lambda 内部调用非静态成员函数 update_status */
        auto *pSD_card = static_cast<SD_Card *> (timer->user_data);
        pSD_card->update_status();
    }, SD_CARD_STATUS_UPDATE_RATE, timer_name, this, true);

    /* 取消挂载 */
//    SD_MMC.end();
}

void SD_Card::update_status() {
    /* 使用 4 bit MMC 模式挂载 SD 卡 */
    if (SD_MMC.begin("/sdcard", false, true)) sd_card_status = SD_CARD_OK;
    else sd_card_status = SD_CARD_ERROR;

    /* SD 卡不存在 */
    if (SD_MMC.cardType() == CARD_NONE) sd_card_status = SD_CARD_NOT_PRESENT;

    /* 处理 SD 卡状态 */
    switch (sd_card_status) {
        case SD_CARD_ERROR:
            USB_log.out("SD Card mount failed");
            USB_log.LOG_USE_FS = false;
            break;
        case SD_CARD_NOT_PRESENT:
            USB_log.out("SD Card isn't present");
            USB_log.LOG_USE_FS = false;
            break;
        case SD_CARD_OK:
            USB_log.LOG_USE_FS = true;
//            LV_LOG_USER("SD Card mount successfully");
            break;
    }
}

void *sd_open_cb(lv_fs_drv_t *drv, const char *path, lv_fs_mode_t mode) {
    File *file = new File();

    if (mode == LV_FS_MODE_WR) {
        /* 当目录不存在时创建目录 */
        *file = SD_MMC.open(path, FILE_WRITE, true);
    } else if (mode == LV_FS_MODE_RD) {
        *file = SD_MMC.open(path, FILE_READ, true);
    } else {
        /* 释放内存 */
        delete file;
        return nullptr;
    }

    if (!*file) {
        /* 文件无法打开 */
//        LV_LOG_ERROR("File: %s cannot open", path);

        delete file;
        return nullptr;
    }

    return (void *)file;
}

lv_fs_res_t sd_close_cb(lv_fs_drv_t *drv, void *file_p) {
    File *file = (File *) file_p;
    file->close();

    delete file;

    /* 返回状态码 */
    return LV_FS_RES_OK;
}

lv_fs_res_t sd_read_cb(lv_fs_drv_t *drv, void *file_p, void *buf, uint32_t btr, uint32_t *br) {
    File *file = (File *) file_p;
    *br = file->read((uint8_t *)buf, btr);

    return (*br > 0) ? LV_FS_RES_OK : LV_FS_RES_FS_ERR;
}

lv_fs_res_t sd_write_cb(lv_fs_drv_t *drv, void *file_p, const void *buf, uint32_t btw, uint32_t *bw) {
    File *file = (File *)file_p;
    *bw = file->write((const uint8_t *)buf, btw);

    return (*bw > 0) ? LV_FS_RES_OK : LV_FS_RES_FS_ERR;
}

/* 定位文件指针回调函数 */
lv_fs_res_t sd_seek_cb(lv_fs_drv_t *drv, void *file_p, uint32_t pos, lv_fs_whence_t whence) {
    File *file = (File *)file_p;
    bool result = file->seek(pos, (whence == LV_FS_SEEK_SET) ? SeekSet :
                                  (whence == LV_FS_SEEK_CUR) ? SeekCur : SeekEnd);

    return result ? LV_FS_RES_OK : LV_FS_RES_FS_ERR;
}

lv_fs_res_t sd_tell_cb(lv_fs_drv_t *drv, void *file_p, uint32_t *pos_p) {
    File *file = (File *)file_p;
    *pos_p = file->position();

    return LV_FS_RES_OK;
}

void * sd_dir_open_cb(lv_fs_drv_t *drv, const char *path) {
    File *dir = new File();
    *dir = SD_MMC.open(path, FILE_READ, true);

    if (!*dir || !dir->isDirectory()) {
        /* 目录打开失败或非目录时释放内存 */
        delete dir;
        return nullptr;
    }

    return (void *)dir;
}

lv_fs_res_t sd_dir_read_cb(lv_fs_drv_t *drv, void *rddir_p, char *fn, uint32_t fn_len) {
    File *dir = (File *)rddir_p;
    File entry = dir->openNextFile();

    if (!entry) {
        fn[0] = '\0';
        return LV_FS_RES_OK;
    }

    strncpy(fn, entry.name(), fn_len - 1);  /* 复制文件名 */
    fn[fn_len - 1] = '\0';  /* 空字符结尾 */
    entry.close();

    return LV_FS_RES_OK;
}

lv_fs_res_t sd_dir_close_cb(lv_fs_drv_t *drv, void *rddir_p) {
    File *dir = (File *)rddir_p;
    dir->close();

    delete dir;
    return LV_FS_RES_OK;
}
