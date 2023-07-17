#include "home.h"
#include "view.h"
#include "app.h"
#include "ui/utils/ui_utils.h"
#include "indev/wifi/wifi.h"
#include "common/time/time.h"
#include "ui/components/status_bar/status_bar.h"

StatusBar statusBar;

extern String APP_NAMES[20];

lv_obj_t *ui_root_panel, *ui_menu_panel;
lv_obj_t *ui_side_bar_panel, *ui_info_label;
lv_obj_t *ui_hour_min_label;

uint16_t focus_num = 0;
uint16_t focus_num_last = 0;
uint8_t  side_bar_out_time_cur = 0;

lv_timer_t *side_bar_in_out_timer, *wifi_status_timer, *home_time_timer;

void side_bar_button_event(lv_event_t *e) {
    lv_obj_t *target = lv_event_get_target(e);
    lv_event_code_t e_code = lv_event_get_code(e);
    if (e_code == LV_EVENT_FOCUSED || e_code == LV_EVENT_CLICKED) {
        if (focus_num == 0) {
            anim_side_bar_spread(ui_side_bar_panel, 0);
        }
        statusBar.set_title(APP_NAMES[lv_obj_get_child_id(target)]);
        focus_num++;
    }
}

/* 检测侧边栏操作超时 */
void side_bar_in_out_update(lv_timer_t *timer) {
    if (focus_num == focus_num_last && focus_num != 0) {
        if (side_bar_out_time_cur < HOME_SIDE_BAR_OUT_TIME) {
            side_bar_out_time_cur++;
        } else {
            side_bar_out_time_cur = 0;
            focus_num = 0;
            focus_num_last = 0;

            statusBar.set_title("ATOM");

            anim_side_bar_shrink(ui_side_bar_panel, 0);
        }
    } else {
        focus_num_last = focus_num;
    }
}

void home_time_update(lv_timer_t *timer) {
    lv_label_set_text(ui_hour_min_label, Time::get_time_str(false).c_str());

//    if (digitalRead(BATTERY_CH) == LOW) {
//        lv_label_set_text(ui_battery_perc_label, "CHARGING");
//    } else {
//        lv_label_set_text(ui_battery_perc_label, "");
//    }
}

void status_bar_update(lv_timer_t *timer) {
    statusBar.update();
}

lv_obj_t *HomePage::page_create() {
    lv_obj_t *scr = lv_obj_create(nullptr);

    /* 创建UI组件 */
    home_ui_init(scr);

    /* 注册HomeApp */
    HomeApp homeApp[10] {};
    homeApp[0].app_init("APPS", &ui_img_app_png, home_app_serial_monitor);
    homeApp[1].app_init("MENU", &ui_img_menu_png, nullptr);
    homeApp[2].app_init("POWER", &ui_img_power_2_png, home_app_esp_sleep_cb);
    homeApp[3].app_init("SETTINGS", &ui_img_settings_png, nullptr);

    /* 动画处理 */
    side_bar_in_out_timer = lv_timer_create(side_bar_in_out_update, 1000, nullptr);

    /* WiFi 状态更新 */
    statusBar.status_bar_timer = lv_timer_create(status_bar_update, STATUS_BAR_UPDATE_DURING, nullptr);

    /* 时间更新 */
    home_time_timer = lv_timer_create(home_time_update, 1000, nullptr);

    return scr;
}

lv_obj_t *HomePage::page_delete() {
    return nullptr;
}