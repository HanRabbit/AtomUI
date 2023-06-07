#include "app.h"
#include "common/log/log.h"

String APP_NAMES[20];

extern void create_side_bar_button(const void *img_src, lv_event_cb_t button_event);
extern lv_obj_t *ui_side_bar_panel;

void home_app_esp_sleep_cb(lv_event_t *e) {
    esp_deep_sleep_start();
}

void HomeApp::app_init(const char *app_name_, const void *icon_src_, lv_event_cb_t app_event_) {
    icon_src = icon_src_;
    app_name = app_name_;
    app_event = app_event_;
    app_id = apps_max_num;
    apps_max_num ++;

    APP_NAMES[app_id] = app_name;
    create_side_bar_button(icon_src, app_event);
    lv_obj_update_snap(ui_side_bar_panel, LV_ANIM_ON);
}