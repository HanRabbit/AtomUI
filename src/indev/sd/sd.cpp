#include <SD.h>
#include <SD_MMC.h>
#include <driver/sdmmc_host.h>
#include "indev/io_map/io_map.h"
#include "common/log/log.h"

sdmmc_slot_config_t slot_config;

bool sd_card_init() {
    slot_config.clk = (gpio_num_t) SD_CLK;
    slot_config.cmd = (gpio_num_t) SD_CMD;
    slot_config.d0 =  (gpio_num_t) SD_DATA0;
    slot_config.d1 =  (gpio_num_t) SD_DATA1;
    slot_config.d2 =  (gpio_num_t) SD_DATA2;
    slot_config.d3 =  (gpio_num_t) SD_DATA3;
    slot_config.cd =  GPIO_NUM_NC;

    digitalWrite(SD_CLK, PULLUP);
    digitalWrite(SD_CMD, PULLUP);
    digitalWrite(SD_DATA0, PULLUP);
    digitalWrite(SD_DATA1, PULLUP);
    digitalWrite(SD_DATA2, PULLUP);
    digitalWrite(SD_DATA3, PULLUP);

    SD_MMC.setPins(SD_CLK, SD_CMD, SD_DATA0, SD_DATA1, SD_DATA2, SD_DATA3);

    if (!SD_MMC.begin("/sdcard", true, true, 400000)) {
        Log::error("SD Card Mount Failed");
        return false;
    }


    File file = SD_MMC.open("/sdcard/test.txt");

    if (file) {
        Log::msg("File Opened Successfully:");
        while (file.available()) {
            Log::msg(String(file.read()));
        }
        file.close();
    } else {
        Log::error("Error Opening File");
    }

    return true;
}