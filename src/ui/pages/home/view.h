#ifndef ATOM_UI_HOME_VIEW_H
#define ATOM_UI_HOME_VIEW_H

#include <Arduino.h>
#include <lvgl.h>
#include "ui/res/rp/rp.h"

#define HOME_SIDE_BAR_OUT_TIME 1
#define HOME_SIDE_BAR_BG_COLOR 0x0

class HomeApp {
public:
    const void *icon_src;
    const char *app_name;
    lv_event_cb_t app_event;
    uint16_t app_id;

    void app_init(const char *app_name_, const void *icon_src_, lv_event_cb_t app_event_);
};

void home_ui_init(lv_obj_t *scr);

#endif //ATOM_UI_HOME_VIEW_H
