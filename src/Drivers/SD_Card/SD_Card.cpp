#include "SD_Card.h"

void SD_Card::init() {
    // 使用 SDMMC 主机模式配置
    sdmmc_host_t host = SDMMC_HOST_DEFAULT();

    // 配置 SD 卡引脚
    sdmmc_slot_config_t slot_config;
    slot_config.clk   = SD_CLK;
    slot_config.cmd   = SD_CMD;
    slot_config.d0    = SD_DATA0;
    slot_config.d1    = SD_DATA1;
    slot_config.d2    = SD_DATA2;
    slot_config.d3    = SD_DATA3;
    slot_config.cd    = SD_DATA3;
    slot_config.wp    = SDMMC_SLOT_NO_WP;

    slot_config.flags = 0;
    slot_config.width = 1;  // 如果使用 4-bit 模式，设置为 4
    slot_config.flags |= SDMMC_SLOT_FLAG_INTERNAL_PULLUP; // 启用内部上拉电阻

    // 配置挂载参数
    esp_vfs_fat_mount_config_t mount_config = {
        .format_if_mount_failed = true,
        .max_files = 5,
        .allocation_unit_size = 16 * 1024
    };

    // 初始化 SD 卡
    sdmmc_card_t* card;

    // 初始化 SD 卡
    esp_err_t ret = esp_vfs_fat_sdmmc_mount("/sdcard", &host, &slot_config, &mount_config, &card);

    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            lv_log("Failed to mount filesystem. "
                           "If you want the card to be formatted, set format_if_mount_failed = true.");
        } else {
            lv_log("Failed to initialize the card (%s). "
                          "Make sure SD card lines have pull-up resistors in place.\n",
                          esp_err_to_name(ret));
        }
        return;
    }

    // 打印 SD 卡信息
    sdmmc_card_print_info(stdout, card);

    // 读取文件示例
    File file = SD.open("/sdcard/hello.txt");
    if (!file) {
        Serial.println("Failed to open file for reading");
        return;
    }
    Serial.println("File Content:");
    while (file.available()) {
        Serial.write(file.read());
    }
    file.close();
}
