#include <Arduino.h>
#include "Drivers/Drivers.h"

Drivers drivers;

void setup() {
    /* LVGL 初始化 */
    lv_init();

    /* 外围器件初始化 */
    drivers.init();

    lv_tick_set_cb(reinterpret_cast<lv_tick_get_cb_t> (millis));
}

void loop() {
    lv_task_handler(); /* let the GUI do its work */
}
