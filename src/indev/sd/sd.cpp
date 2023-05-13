#include "sd.h"

bool sd_card_init() {
    SD_MMC.setPins(SD_CLK, SD_CMD, SD_D0, SD_D1, SD_D2, SD_D3);
    for (uint8_t retry_num = 0; retry_num < SD_CARD_RETRY_NUM; retry_num ++) {
        /* 初始化SD_MMC */
        if (SD_MMC.begin("/sdcard", false, true)) {
            Log::msg("SD SIZE", String(SD_MMC.cardSize() / (1024 * 1024)));
            Log::msg("FILES SYSTEM SIZE", String(SD_MMC.totalBytes()));
            Log::msg("FILES SYSTEM USED SIZE", String(SD_MMC.usedBytes()));
            return true;
        }
    }
    /* 抛出异常 */
    Log::error("05", "Card Mount Failed");
    return false;
}