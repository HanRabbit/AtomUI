#include "WiFiConfigPage.h"
#include "UI/Res/Components/StatusBar/StatusBar.h"
#include "UI/Utils/UIGroup/UIGroup.h"
#include "UI/Themes/Themes.h"
#include "Common/MessageManager/Account.h"
#include "Common/WiFi/WiFi.h"
#include "UI/Utils/PageManager/PageManager.h"

lv_obj_t *WiFiConfigPage::create() {
    lv_obj_t *root = lv_obj_create(nullptr);
    StatusBar.create(root);

    lv_set_default_theme();

    lv_obj_t *wifiStatusPanel = lv_obj_create(root);
    lv_obj_set_size(wifiStatusPanel, 300, 140);
    lv_obj_set_style_bg_color(wifiStatusPanel, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_align(wifiStatusPanel, LV_ALIGN_CENTER, 0, -16);
    lv_obj_set_flex_align(wifiStatusPanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_flex_flow(wifiStatusPanel, LV_FLEX_FLOW_COLUMN);

    lv_obj_t *containerSSID = lv_obj_create(wifiStatusPanel);
    lv_obj_set_width(containerSSID, lv_pct(100));
    lv_obj_set_height(containerSSID, 30);
    lv_obj_set_style_border_width(containerSSID, 0, LV_PART_MAIN);
    lv_obj_set_flex_align(containerSSID, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_flex_flow(containerSSID, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_bg_color(containerSSID, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_pad_all(containerSSID, 0, LV_PART_MAIN);

    lv_obj_t *labelSSID_Title = lv_label_create(containerSSID);
    lv_label_set_text(labelSSID_Title, "SSID");
    lv_obj_set_style_text_color(labelSSID_Title, lv_color_hex(0x2A82E4), LV_PART_MAIN);
    lv_obj_set_style_text_font(labelSSID_Title, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_width(labelSSID_Title, 50);

    lv_obj_t *labelSSID_Value = lv_label_create(containerSSID);
    lv_label_set_text(labelSSID_Value, "--Not Connected--");
    lv_obj_set_style_text_color(labelSSID_Value, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_text_font(labelSSID_Value, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_width(labelSSID_Value, 170);
    lv_label_set_text(labelSSID_Value, WiFi.SSID().c_str());

    lv_obj_t *containerPWD = lv_obj_create(wifiStatusPanel);
    lv_obj_set_width(containerPWD, lv_pct(100));
    lv_obj_set_height(containerPWD, 30);
    lv_obj_set_style_border_width(containerPWD, 0, LV_PART_MAIN);
    lv_obj_set_flex_align(containerPWD, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_flex_flow(containerPWD, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_bg_color(containerPWD, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_pad_all(containerPWD, 0, LV_PART_MAIN);

    lv_obj_t *labelPWD_Title = lv_label_create(containerPWD);
    lv_label_set_text(labelPWD_Title, "PWD");
    lv_obj_set_style_text_color(labelPWD_Title, lv_color_hex(0x2A82E4), LV_PART_MAIN);
    lv_obj_set_style_text_font(labelPWD_Title, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_width(labelPWD_Title, 50);

    lv_obj_t *labelPWD_Value = lv_label_create(containerPWD);
    lv_label_set_text(labelPWD_Value, "--Not Connected--");
    lv_obj_set_style_text_color(labelPWD_Value, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_text_font(labelPWD_Value, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_width(labelPWD_Value, 170);
    lv_label_set_text(labelPWD_Value, WiFi.psk() == "" ? "-- NULL --" : WiFi.psk().c_str());


    lv_obj_t *containerMAC = lv_obj_create(wifiStatusPanel);
    lv_obj_set_width(containerMAC, lv_pct(100));
    lv_obj_set_height(containerMAC, 30);
    lv_obj_set_style_border_width(containerMAC, 0, LV_PART_MAIN);
    lv_obj_set_flex_align(containerMAC, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_flex_flow(containerMAC, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_bg_color(containerMAC, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_pad_all(containerMAC, 0, LV_PART_MAIN);

    lv_obj_t *labelMAC_Title = lv_label_create(containerMAC);
    lv_label_set_text(labelMAC_Title, "MAC");
    lv_obj_set_style_text_color(labelMAC_Title, lv_color_hex(0x2A82E4), LV_PART_MAIN);
    lv_obj_set_style_text_font(labelMAC_Title, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_width(labelMAC_Title, 50);

    lv_obj_t *labelMAC_Value = lv_label_create(containerMAC);
    lv_label_set_text(labelMAC_Value, "--Not Connected--");
    lv_obj_set_style_text_color(labelMAC_Value, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_text_font(labelMAC_Value, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_width(labelMAC_Value, 170);
    lv_label_set_text(labelMAC_Value, WiFi.macAddress().c_str());


    lv_obj_t *buttonWifiConnect = lv_btn_create(root);
    lv_obj_set_width(buttonWifiConnect, 140);
    lv_obj_set_height(buttonWifiConnect, 36);
    lv_obj_align(buttonWifiConnect, LV_ALIGN_BOTTOM_MID, 0, -14);
    lv_obj_set_style_bg_color(buttonWifiConnect, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_add_event_cb(buttonWifiConnect, [] (lv_event_t *event) {
        PageManager.p_push("APP/WIFI_CONFIG", PM_SCR_ANIM_MOVE_LEFT);
    }, LV_EVENT_CLICKED, nullptr);
    
    lv_obj_t *labelWifiConnect = lv_label_create(buttonWifiConnect);
    lv_label_set_text(labelWifiConnect, "CONNECT");
    lv_obj_set_style_text_color(labelWifiConnect, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_align(labelWifiConnect, LV_ALIGN_CENTER);
    
    lv_group_add_obj(group, StatusBar.back_button);
    lv_group_add_obj(group, buttonWifiConnect);

    /* 发布 APP 标题名称消息 */
    publisher.publish(MSG_ID_SYSTEM_APP_TITLE, "WIFI STATUS");

    return root;
}

lv_obj_t *WiFiConfigPage::del() {
    return nullptr;
}