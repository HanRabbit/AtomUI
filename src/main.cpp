#include <Arduino.h>
#include "Common/Common.h"
#include "Drivers/Drivers.h"
#include "UI/Apps/Apps.h"

Drivers drivers;
Common common;
Apps apps;

void setup() {
    /* LVGL 初始化 */
    lv_init();

    lv_tick_set_cb(reinterpret_cast<lv_tick_get_cb_t> (millis));

    /* 外围器件初始化 */
    drivers.init();

    /* Common 抽象层初始化 */
    common.init();

    /* 应用初始化 */
    apps.init();

    apps.launch();
}

void loop() {
    lv_task_handler(); /* let the GUI do its work */
}
