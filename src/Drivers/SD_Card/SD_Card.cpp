#include "SD_Card.h"

void *sd_open_cb(lv_fs_drv_t *drv, const char *path, lv_fs_mode_t mode);
lv_fs_res_t sd_close_cb(lv_fs_drv_t *drv, void *file_p);
lv_fs_res_t sd_read_cb(lv_fs_drv_t *drv, void *file_p, void *buf, uint32_t btr, uint32_t *br);
lv_fs_res_t sd_write_cb(lv_fs_drv_t *drv, void *file_p, const void *buf, uint32_t btw, uint32_t *bw);
lv_fs_res_t sd_seek_cb(lv_fs_drv_t *drv, void *file_p, uint32_t pos, lv_fs_whence_t whence);
lv_fs_res_t sd_tell_cb(lv_fs_drv_t *drv, void *file_p, uint32_t *pos_p);

void *sd_dir_open_cb(lv_fs_drv_t *drv, const char *path);
lv_fs_res_t sd_dir_read_cb(lv_fs_drv_t *drv, void *rddir_p, char *fn, uint32_t fn_len);
lv_fs_res_t sd_dir_close_cb(lv_fs_drv_t *drv, void *rddir_p);

void testLvglFileIO() {
    const char *filePath = "H:/han.txt";  // LVGL文件系统中的文件路径

    // 1. 创建并打开文件进行写入
    lv_fs_file_t file;
    lv_fs_res_t res = lv_fs_open(&file, filePath, LV_FS_MODE_WR);
    if (res != LV_FS_RES_OK) {
        LV_LOG_USER("Failed to open file for writing: %d", res);
        return;
    }

    // 2. 写入数据
    const char *testData = "Hello, LVGL and SD_MMC!";
    uint32_t bytesWritten;
    res = lv_fs_write(&file, testData, strlen(testData), &bytesWritten);
    if (res != LV_FS_RES_OK || bytesWritten != strlen(testData)) {
        LV_LOG_USER("Failed to write all data to file: %d", res);
    } else {
        LV_LOG_USER("Wrote %u bytes to file: %s", bytesWritten, testData);
    }
    lv_fs_close(&file);  // 关闭文件

    // 3. 重新打开文件进行读取
    res = lv_fs_open(&file, filePath, LV_FS_MODE_RD);
    if (res != LV_FS_RES_OK) {
        LV_LOG_USER("Failed to open file for reading: %d", res);
        return;
    }

    // 4. 读取数据
    char readBuffer[64];
    uint32_t bytesRead;
    res = lv_fs_read(&file, readBuffer, sizeof(readBuffer) - 1, &bytesRead);
    if (res == LV_FS_RES_OK && bytesRead > 0) {
        readBuffer[bytesRead] = '\0';  // 添加字符串结束符
        LV_LOG_USER("Read %u bytes from file: %s", bytesRead, readBuffer);

        // 5. 验证数据
        if (strcmp(testData, readBuffer) == 0) {
            LV_LOG_USER("LVGL File read/write test passed!");
        } else {
            LV_LOG_USER("LVGL File read/write test failed!");
        }
    } else {
        LV_LOG_USER("Failed to read data from file: %d", res);
    }
    lv_fs_close(&file);  // 关闭文件
}

/* SD 卡初始化 */
void SD_Card::init() {
    lv_fs_drv_t fs_drv;
    lv_fs_drv_init(&fs_drv);

    /* 设置 SD 卡引脚 */
    SD_MMC.setPins(SD_CLK, SD_CMD, SD_DATA0, SD_DATA1, SD_DATA2, SD_DATA3);

    /* 使用 4 bit MMC 模式挂载 SD 卡 */
    if (SD_MMC.begin("/sdcard", false, true)) sd_card_status = SD_CARD_OK;
    else sd_card_status = SD_CARD_ERROR;

    /* SD 卡不存在 */
    if (SD_MMC.cardType() == CARD_NONE) sd_card_status = SD_CARD_NOT_PRESENT;

    /* 使用 4 bit MMC 模式挂载 SD 卡 */
//    ::update_status();

    /* 处理 SD 卡状态 */
    switch (sd_card_status) {
        case SD_CARD_ERROR:
            LV_LOG_ERROR("SD Card mount failed");
            break;
        case SD_CARD_NOT_PRESENT:
            LV_LOG_ERROR("SD Card isn't present");
            break;
        case SD_CARD_OK:
            LV_LOG_USER("SD Card mount successfully");
            break;
    }

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

    testLvglFileIO();

    /* 设置定时器刷新状态 */
    sd_status_timer = lv_timer_create([](lv_timer_t * timer) {
        auto *pSdCard = static_cast<SD_Card *>(timer->user_data);
        pSdCard->update_status();
    }, 5000, this);

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
            LV_LOG_USER("SD Card mount failed");
            break;
        case SD_CARD_NOT_PRESENT:
            LV_LOG_USER("SD Card isn't present");
            break;
        case SD_CARD_OK:
            LV_LOG_USER("SD Card mount successfully");
            break;
    }
}

void *sd_open_cb(lv_fs_drv_t * drv, const char * path, lv_fs_mode_t mode) {
    File *file = new File();

    if (mode == LV_FS_MODE_WR) {
        *file = SD_MMC.open(path, FILE_WRITE);
    } else if (mode == LV_FS_MODE_RD) {
        *file = SD_MMC.open(path, FILE_READ);
    } else {
        /* 释放内存 */
        delete file;
        return nullptr;
    }

    if (!*file) {
        /* 文件无法打开 */
        LV_LOG_ERROR("File: %s cannot open", path);

        delete file;
        return nullptr;
    }

    return (void *)file;
}

lv_fs_res_t sd_close_cb(lv_fs_drv_t * drv, void * file_p) {
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
    *dir = SD_MMC.open(path);

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
