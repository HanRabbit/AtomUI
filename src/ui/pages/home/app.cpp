#include "app.h"
#include "common/log/log.h"
#include "common/esp_sleep/esp_sleep.h"
#include "ui/utils/pm/pm.h"
#include "ui/components/status_bar/status_bar.h"

String APP_NAMES[20];

extern void create_side_bar_button(const void *img_src, lv_event_cb_t button_event);
extern lv_obj_t *ui_side_bar_panel;
extern PageManager pageManager;

extern lv_timer_t *side_bar_in_out_timer, *home_time_timer;
extern StatusBar statusBar;

void home_app_esp_sleep_cb(lv_event_t *e) {
    esp_sleep_start();
}

void home_app_serial_monitor(lv_event_t *e) {
    pageManager.push("PAGE/SERIAL_MONITOR", PM_SCR_ANIM_MOVE_TOP);
}

void home_app_translate(lv_event_t *e) {
    pageManager.push("PAGE/TRANSLATE", PM_SCR_ANIM_MOVE_TOP);
}

void home_app_ota_update(lv_event_t *e) {
    pageManager.push("PAGE/OTAPage", PM_SCR_ANIM_MOVE_TOP);
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
