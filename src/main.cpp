#include "indev/indev.h"
#include "ui/app.h"
#include "indev/wifi/wifi.h"

void setup() {
    lv_init();

    lv_port_drv_init();
    
    app_init();

    wifi_init();
}

void loop() {
    lv_timer_handler();
}
