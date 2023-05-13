#ifndef ATOM_UI_SD_H
#define ATOM_UI_SD_H

#include <SD_MMC.h>
#include "common/log/log.h"
#include "indev/io_map/io_map.h"

#define SD_CARD_RETRY_NUM 4

static String SD_CARD_MSG_NAME = "SD CARD";

bool sd_card_init();

#endif //ATOM_UI_SD_H
