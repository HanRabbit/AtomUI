#ifndef SD_CARD_H
#define SD_CARD_H

#include <Arduino.h>
#include <lvgl.h>
#include <SD_MMC.h>

#include "Drivers/IO_Map/IO_map.h"
#include "Common/Common.h"

/* SD 卡状态刷新频率 (ms) */
#define SD_CARD_STATUS_UPDATE_RATE 5000

typedef enum {
    SD_CARD_OK,
    SD_CARD_NOT_PRESENT,
    SD_CARD_ERROR
} sd_card_status_t;

class SD_Card {
public:
    const char *timer_name = "FS_TIMER";
    sd_card_status_t sd_card_status;

    void init();
    void update_status();
};

#endif //SD_CARD_H
