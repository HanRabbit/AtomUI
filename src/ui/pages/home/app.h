#ifndef ATOM_UI_HOME_APP_H
#define ATOM_UI_HOME_APP_H

#include <Arduino.h>
#include <lvgl.h>

static uint16_t apps_max_num = 0;

void home_app_esp_sleep_cb(lv_event_t *e);
void home_app_serial_monitor(lv_event_t *e);
void home_app_translate(lv_event_t *e);
void home_app_ota_update(lv_event_t *e);

class HomeApp {
public:
    const void *icon_src;
    const char *app_name;
    lv_event_cb_t app_event;
    uint16_t app_id;

    void app_init(const char *app_name_, const void *icon_src_, lv_event_cb_t app_event_);
};

#endif //ATOM_UI_HOME_APP_H