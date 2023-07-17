#include "status_bar.h"
#include "common/log/log.h"
#include "ui/res/rp/rp.h"
#include "indev/wifi/wifi.h"

void StatusBar::create_status_bar(lv_obj_t *root) {
    lv_obj_t *ui_status_bar = lv_obj_create(root);
    lv_obj_set_width(ui_status_bar, 320);
    lv_obj_set_height(ui_status_bar, 18);
    lv_obj_set_x(ui_status_bar, 0);
    lv_obj_set_y(ui_status_bar, margin_y);
    lv_obj_set_align(ui_status_bar, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_status_bar, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(ui_status_bar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_status_bar, lv_color_hex(0x000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_status_bar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_status_bar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifi_mode = lv_label_create(ui_status_bar);
    lv_obj_set_width(ui_wifi_mode, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_wifi_mode, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_wifi_mode, 20);
    lv_obj_set_y(ui_wifi_mode, 0);
    lv_obj_set_align(ui_wifi_mode, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_wifi_mode, "");
    lv_obj_set_style_text_font(ui_wifi_mode, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifi_icon = lv_img_create(ui_status_bar);
    lv_img_set_src(ui_wifi_icon, &ui_img_wifi_closed_png);
    lv_obj_set_width(ui_wifi_icon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_wifi_icon, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_wifi_icon, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_wifi_icon, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_wifi_icon, LV_OBJ_FLAG_SCROLLABLE);

    ui_info_label = lv_label_create(ui_status_bar);
    lv_obj_set_width(ui_info_label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_info_label, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_info_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_info_label, "ATOM");
    lv_obj_set_style_text_font(ui_info_label, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_battery_icon = lv_img_create(ui_status_bar);
    lv_img_set_src(ui_battery_icon, &ui_img_battery_png);
    lv_obj_set_width(ui_battery_icon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_battery_icon, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_battery_icon, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_battery_icon, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_battery_icon, LV_OBJ_FLAG_SCROLLABLE);

    ui_battery_perc_label = lv_label_create(ui_status_bar);
    lv_obj_set_width(ui_battery_perc_label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_battery_perc_label, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_battery_perc_label, -20);
    lv_obj_set_y(ui_battery_perc_label, 0);
    lv_obj_set_align(ui_battery_perc_label, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_battery_perc_label, "");
    lv_obj_set_style_text_font(ui_battery_perc_label, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void StatusBar::set_title(String st) {
    status.title = st;
    lv_label_set_text(ui_info_label, status.title.c_str());
}

void StatusBar::update() {
    status.wifi_mode = WiFiClass::getMode();
    status.wifi_status = (wifi_status_t) get_wifi_status();

    String wifi_mode;
    switch (status.wifi_mode) {
        case WIFI_MODE_NULL:
            wifi_mode = "";
            break;
        case WIFI_MODE_STA:
            wifi_mode = "STA";
            break;
        case WIFI_MODE_AP:
            wifi_mode = "AP";
            break;
        case WIFI_MODE_APSTA:
            wifi_mode = "APSTA";
            break;
        case WIFI_MODE_MAX:
            wifi_mode = "MAX";
            break;
    }

    switch (status.wifi_status) {
        case CONNECTED:
            lv_img_set_src(ui_wifi_icon, &ui_img_wifi_png);
            break;
        case DISCONNECTED:
            lv_img_set_src(ui_wifi_icon, &ui_img_wifi_closed_png);
            break;
        default:
            Log::error("WIFI", "Wifi icon is not illegal");
    }

    lv_label_set_text(ui_wifi_mode, wifi_mode.c_str());
    lv_label_set_text(ui_battery_perc_label, String(status.battery).c_str());
    lv_label_set_text(ui_info_label, status.title.c_str());
}