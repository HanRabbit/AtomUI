#include "sd.h"

void lv_fs_test() {
    lv_fs_file_t file;
    lv_fs_res_t res;

    res = lv_fs_open(&file, "H:/test.txt", LV_FS_MODE_RD);
    if (res != LV_FS_RES_OK) {
        Log::error(ERROR_CODE_FILE_SYSTEM_INIT_FAILED);
    } else {
        Log::msg("Open OK");
        uint32_t read_num;
        uint8_t buf[20];
        res = lv_fs_read(&file, buf, 20, &read_num);
        LOG_.printf("READ: %s", buf);
        lv_fs_close(&file);
    }
}

bool sd_card_init() {
    pinMode(SD_D0, PULLUP);
    pinMode(SD_D1, PULLUP);
    pinMode(SD_D2, PULLUP);
    pinMode(SD_D3, PULLUP);

    SD_MMC.setPins(SD_CLK, SD_CMD, SD_D0, SD_D1, SD_D2, SD_D3);
    for (uint8_t retry_num = 0; retry_num < SD_CARD_RETRY_NUM; retry_num ++) {
        /* 初始化SD_MMC */
        if (SD_MMC.begin("/H", false, true, 10000)) {
//            f_mount(&fat_fs, "/sdcard", 1);
            Log::msg("SD SIZE", String(SD_MMC.cardSize() / (1024 * 1024)));
            Log::msg("FILES SYSTEM SIZE", String(SD_MMC.totalBytes()));
            Log::msg("FILES SYSTEM USED SIZE", String(SD_MMC.usedBytes()));

//            lv_fs_fatfs_init();
            lv_fs_test();
            return true;
        }
    }
    /* 抛出异常 */
    Log::error(ERROR_CODE_SD_MOUNT_FAILED);
    return false;
}