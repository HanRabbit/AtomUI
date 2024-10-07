#include "StatusBar.h"

#include "Common/TimerManager/TimerManager.h"
#include "Common/MessageManager/Account.h"

Status_Bar StatusBar;

void status_bar_update_wifi(String status) {
    /* 更新 Wi-Fi 状态 */
    if (status == MSG_CONTENT_WIFI_CONNECTED) {
        lv_image_set_src(StatusBar.wifi_icon, COMP_WIFI_OPEN_IMG_PATH);
    } else {
        lv_image_set_src(StatusBar.wifi_icon, COMP_WIFI_CLOSE_IMG_PATH);
    }
}

void status_bar_update_battery(String percent) {
    /* 更新电池电量 */
    int w = percent.toFloat() * 18.0;
    lv_obj_set_width(StatusBar.battery_inside, w);
}


void Status_Bar::create(lv_obj_t *root) {
    lv_obj_t *ui_status_bar = lv_obj_create(root);
    lv_obj_set_width(ui_status_bar, 320);
    lv_obj_set_height(ui_status_bar, 20);
    lv_obj_set_x(ui_status_bar, 0);
    lv_obj_set_y(ui_status_bar, 0);
    lv_obj_set_align(ui_status_bar, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_status_bar, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(ui_status_bar, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(ui_status_bar, lv_color_hex(0x000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(ui_status_bar, 255, LV_PART_MAIN);
    lv_obj_set_style_border_width(ui_status_bar, 0, LV_PART_MAIN);

    back_button = lv_btn_create(ui_status_bar);
    lv_obj_set_width(back_button, 20);
    lv_obj_set_height(back_button, 20);
    lv_obj_set_x(back_button, -10);
    lv_obj_set_style_bg_color(back_button, lv_color_hex(0x000000), LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(back_button, 1, LV_PART_MAIN);
    lv_obj_set_style_border_color(back_button, lv_color_hex(0xffffff), LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(back_button, lv_color_hex(0x000000), LV_STATE_DEFAULT);
    lv_obj_set_align(back_button, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(back_button, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(back_button, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_event_cb(
            back_button, [](lv_event_t *e) {
        PageManager.p_push("PAGE/HOME", PM_SCR_ANIM_MOVE_BOTTOM);
    }, LV_EVENT_RELEASED, nullptr);

    back_icon = lv_img_create(back_button);
    lv_img_set_src(back_icon, COMP_BACK_IMG_PATH);
    lv_obj_set_width(back_icon, LV_SIZE_CONTENT);
    lv_obj_set_height(back_icon, LV_SIZE_CONTENT);
    lv_obj_set_align(back_icon, LV_ALIGN_CENTER);
    lv_obj_add_flag(back_icon, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(back_icon, LV_OBJ_FLAG_SCROLLABLE);

    wifi_mode = lv_label_create(ui_status_bar);
    lv_obj_set_width(wifi_mode, LV_SIZE_CONTENT);
    lv_obj_set_height(wifi_mode, LV_SIZE_CONTENT);
    lv_obj_set_x(wifi_mode, 30);
    lv_obj_set_y(wifi_mode, 0);
    lv_obj_set_align(wifi_mode, LV_ALIGN_LEFT_MID);
    lv_label_set_text(wifi_mode, "");
    lv_obj_set_style_text_font(wifi_mode, &lv_font_montserrat_12, LV_PART_MAIN);

    wifi_icon = lv_img_create(ui_status_bar);
    lv_img_set_src(wifi_icon, COMP_WIFI_CLOSE_IMG_PATH);
    lv_obj_set_width(wifi_icon, LV_SIZE_CONTENT);
    lv_obj_set_height(wifi_icon, LV_SIZE_CONTENT);
    lv_obj_set_x(wifi_icon, 10);
    lv_obj_set_align(wifi_icon, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(wifi_icon, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(wifi_icon, LV_OBJ_FLAG_SCROLLABLE);

    info_label = lv_label_create(ui_status_bar);
    lv_obj_set_width(info_label, LV_SIZE_CONTENT);
    lv_obj_set_height(info_label, LV_SIZE_CONTENT);
    lv_obj_set_align(info_label, LV_ALIGN_CENTER);
    lv_label_set_text(info_label, "ATOM");
    lv_obj_set_style_text_font(info_label, &lv_font_montserrat_14, LV_PART_MAIN);

    battery_icon = lv_obj_create(ui_status_bar);
    lv_obj_set_width(battery_icon, 20);
    lv_obj_set_height(battery_icon, 10);
    lv_obj_set_align(battery_icon, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(battery_icon, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(battery_icon, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(battery_icon, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_border_width(battery_icon, 1, LV_PART_MAIN);
    lv_obj_set_style_border_color(battery_icon, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_radius(battery_icon, 2, LV_PART_MAIN);

    battery_inside = lv_obj_create(battery_icon);
    lv_obj_set_width(battery_inside, 18);
    lv_obj_set_height(battery_inside, 8);
    lv_obj_set_x(battery_inside, -13);
    lv_obj_set_align(battery_inside, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(battery_inside, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(battery_inside, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(battery_inside, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_radius(battery_inside, 2, LV_PART_MAIN);

    battery_perc_label = lv_label_create(ui_status_bar);
    lv_obj_set_width(battery_perc_label, LV_SIZE_CONTENT);
    lv_obj_set_height(battery_perc_label, LV_SIZE_CONTENT);
    lv_obj_set_x(battery_perc_label, -20);
    lv_obj_set_y(battery_perc_label, 0);
    lv_obj_set_align(battery_perc_label, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(battery_perc_label, "");
    lv_obj_set_style_text_font(battery_perc_label, &lv_font_montserrat_12, LV_PART_MAIN);

    /* 订阅消息回调函数，刷新状态栏 */
    subscriber.subcribe(MSG_ID_WIFI_STATUS, status_bar_update_wifi);
    subscriber.subcribe(MSG_ID_BATTERY_PERCENT, status_bar_update_battery);
}
