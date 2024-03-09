#include "indev/indev.h"
#include "ui/app.h"
#include "common/wifi/wifi.h"
#include "indev/self_check/self_check.h"
#include "common/time/time.h"

void setup() {
    lv_init();

    lv_port_drv_init();
    
    app_init();

    wifi_init();

    time_init();

    sys_indev_check();
}

void loop() {
    lv_timer_handler();
}
