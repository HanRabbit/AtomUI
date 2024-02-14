#include "esp_sleep.h"
#include "indev/io_map/io_map.h"

void esp_sleep_start() {
    // gpio_config_t io_conf;
    // io_conf.mode = GPIO_MODE_INPUT;
    // io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    // io_conf.intr_type = GPIO_INTR_DISABLE;
    // io_conf.pin_bit_mask = (1ULL << GPIO_NUM_2);
    // gpio_config(&io_conf);

//    gpio_sleep_set_pull_mode(GPIO_NUM_2, GPIO_PULLUP_PULLDOWN);
//    esp_sleep_enable_ext0_wakeup(GPIO_NUM_2, HIGH);
}
