#include "home.h"
#include "view.h"
#include "app.h"
#include "ui/utils/ui_utils.h"
#include "common/time/time.h"
#include "ui/components/status_bar/status_bar.h"
#include "ui/utils/page_manager/page_manager.h"

#include "ui/utils/msg_manager/msg_manager.h"

extern StatusBar statusBar;

HomeAppManager homeAppManager{};

extern String APP_NAMES[20];
extern PageManager pageManager;
extern MsgManager msgManager;

lv_obj_t *ui_root_panel, *ui_menu_panel;
lv_obj_t *ui_side_bar_panel;
lv_obj_t *ui_hour_min_label;

uint16_t focus_num = 0;
uint16_t focus_num_last = 0;
uint8_t  side_bar_out_time_cur = 0;

lv_timer_t *side_bar_in_out_timer, *wifi_status_timer, *home_time_timer;

lv_obj_t *scr;

extern lv_obj_t *ui_root_panel;

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
}

void status_bar_update(lv_timer_t *timer) {
    statusBar.update();
}

void home_page_timers_event(lv_event_t *e) {
    /* 动画处理 */
    side_bar_in_out_timer = lv_timer_create(side_bar_in_out_update, 1000, nullptr);

    /* WiFi 状态更新 */
    statusBar.status_bar_timer = lv_timer_create(status_bar_update, STATUS_BAR_UPDATE_DURING, nullptr);

    /* 时间更新 */
    home_time_timer = lv_timer_create(home_time_update, 1000, nullptr);

    lv_timer_ready(side_bar_in_out_timer);
    lv_timer_ready(statusBar.status_bar_timer);
    lv_timer_ready(home_time_timer);
}

lv_obj_t *HomePage::page_create() {
    scr = lv_obj_create(nullptr);
    lv_obj_add_event_cb(scr, home_page_timers_event, LV_EVENT_SCREEN_LOADED, nullptr);

    /* 创建UI组件 */
    home_ui_init(scr);

    /* 注册HomeApp */
    homeAppManager.add_app("APPS", &ui_img_app_png, nullptr);
    homeAppManager.add_app("TRANSLATE", &ui_img_translate_png, home_app_translate);
    homeAppManager.add_app("SERIAL MONITOR", &ui_img_serial_png, home_app_serial_monitor);
    homeAppManager.add_app("POWER", &ui_img_power_2_png, home_app_esp_sleep_cb);
    homeAppManager.add_app("SETTINGS", &ui_img_settings_png, nullptr);
    homeAppManager.add_app("OTA UPDATE", &ui_img_update_png, home_app_ota_update);

    // String msg = "ATOM POCKET";
    // msgManager.send_msg("PROJECT_NAME", &msg);

    String msg_content = msgManager.get_msg("PROJECT_NAME");
    Log::msg(String(msg_content.toInt()));

    return scr;
}

lv_obj_t *HomePage::page_delete() {
    lv_timer_del(side_bar_in_out_timer);
//    lv_timer_del(statusBar.status_bar_timer);
    lv_timer_del(home_time_timer);

    free((int *) malloc(sizeof (int)));
    lv_obj_remove_event_cb(ui_side_bar_panel, nullptr);
//    lv_obj_del(ui_root_panel);
    lv_mem_buf_free_all();

    return nullptr;
}