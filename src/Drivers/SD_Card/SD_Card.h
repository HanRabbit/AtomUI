#ifndef SD_CARD_H
#define SD_CARD_H

#include <Arduino.h>
#include <FS.h>
#include <SD.h>
#include <lvgl.h>
#include <driver/sdmmc_host.h>
#include <esp_err.h>
#include <esp_vfs_fat.h>
#include <misc/lv_log.h>
#include <sdmmc_cmd.h>

#include "Drivers/IO_Map/IO_map.h"

class SD_Card {
public:
  void init();
};

#endif //SD_CARD_H
