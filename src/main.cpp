#include <Arduino.h>
#include "Drivers/Drivers.h"

Drivers drivers;

void setup() {
    /* LVGL 初始化 */
    lv_init();

    /* 外围器件初始化 */
    drivers.init();
}

void loop() {
    lv_task_handler(); /* let the GUI do its work */
}
