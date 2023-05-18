#include "home_events.h"
#include "indev/battery/battery.h"
#include "indev/wifi/wifi.h"
#include "common/time/time.h"

extern lv_obj_t *ui_battery_label, *ui_timePanel, *ui_statusBar, *scr, *ui_timeLabel, *ui_yearLabel;

String time_hour_min_str, time_year_str;

void battery_status_show(lv_timer_t *timer) {
    lv_label_set_text(ui_battery_label, ((String)get_battery() + "%").c_str());
}

void time_update(lv_timer_t *timer) {
    if (WiFi.isConnected()) {
        getLocalTime(&time_);
        time_hour_min_str = (time_.tm_hour < 10 ? "0" : "") + String(time_.tm_hour) + ":" + (time_.tm_min < 10 ? "0" : "") + String(time_.tm_min);
        time_year_str = String(time_.tm_year + 1900) + "-" + String(time_.tm_mon + 1) + "-" + String(time_.tm_mday);

        lv_label_set_text(ui_timeLabel, time_hour_min_str.c_str());
        lv_label_set_text(ui_yearLabel, time_year_str.c_str());
    }
}

void ui_event(lv_event_t *e) {
    lv_event_code_t e_code = lv_event_get_code(e);
    if (e_code == LV_EVENT_SCREEN_LOADED) {
        anim_zoom_fade_out(ui_timePanel, 0);
        anim_down(ui_statusBar, 400);
    }
}

void ui_events_handle() {
//    lv_timer_create(battery_status_show, 500, nullptr);
    lv_timer_create(wifi_status_update, 1000, nullptr);
    lv_timer_create(time_update, 2000, nullptr);

    lv_obj_add_event_cb(scr, ui_event, LV_EVENT_ALL, nullptr);
}