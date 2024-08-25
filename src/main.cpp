#include <Arduino.h>
#include "Drivers/Drivers.h"
#include "Common/Common.h"

Drivers drivers;
Common common;

void setup() {
    /* LVGL 初始化 */
    lv_init();

    lv_tick_set_cb(reinterpret_cast<lv_tick_get_cb_t> (millis));

    /* 外围器件初始化 */
    drivers.init();

    /* Common 抽象层初始化 */
    common.init();
}

void loop() {
    lv_task_handler(); /* let the GUI do its work */
}
