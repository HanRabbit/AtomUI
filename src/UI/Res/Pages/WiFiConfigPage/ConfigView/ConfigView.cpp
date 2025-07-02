#include "ConfigView.h"
#include "Common/MessageManager/Account.h"
#include "Common/WiFi/WiFi.h"
#include "UI/Utils/UIGroup/UIGroup.h"
#include "UI/Themes/Themes.h"
#include "UI/Res/Components/StatusBar/StatusBar.h"

lv_obj_t *ConfigViewPage::create() {
    lv_obj_t *root = lv_obj_create(nullptr);
    StatusBar.create(root);

    lv_set_default_theme();

    /* 创建根视图 */
    createRootView(root);

    /* 发布 APP 标题名称消息 */
    publisher.publish(MSG_ID_SYSTEM_APP_TITLE, "WIFI CONFIG");
    
    lv_group_add_obj(group, StatusBar.back_button);

    return root;
}

lv_obj_t *ConfigViewPage::del() {
    /* 删除页面根组件，释放内存 */
    // lv_obj_clean(lv_obj_get_parent(lv_obj_get_child(lv_scr_act(), 0)));

    return nullptr;
}

void ConfigViewPage::createRootView(lv_obj_t *root) {
    // 创建一个容器用于放置输入框和标签
    lv_obj_t *container = lv_obj_create(root);
    lv_obj_set_width(container, 280);
    lv_obj_set_height(container, 120);
    lv_obj_align(container, LV_ALIGN_CENTER, 0, -20);
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_border_width(container, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(container, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_flex_align(container, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_obj_set_style_pad_all(container, 10, LV_PART_MAIN);

    // SSID输入框
    lv_obj_t *ssid_textarea = lv_textarea_create(container);
    lv_obj_set_width(ssid_textarea, 260);
    lv_textarea_set_one_line(ssid_textarea, true);
    lv_obj_set_style_bg_color(ssid_textarea, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_border_width(ssid_textarea, 1, LV_PART_MAIN);
    lv_obj_set_style_border_color(ssid_textarea, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_textarea_set_placeholder_text(ssid_textarea, "Wi-Fi Name");

    // 密码输入框
    lv_obj_t *pwd_textarea = lv_textarea_create(container);
    lv_obj_set_width(pwd_textarea, 260);
    lv_textarea_set_password_mode(pwd_textarea, true);
    lv_textarea_set_one_line(pwd_textarea, true);
    lv_obj_set_style_bg_color(pwd_textarea, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_border_width(pwd_textarea, 1, LV_PART_MAIN);
    lv_obj_set_style_border_color(pwd_textarea, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_textarea_set_placeholder_text(pwd_textarea, "Wi-Fi Password");


    lv_obj_t *buttonWifiConnect = lv_btn_create(root);
    lv_obj_set_width(buttonWifiConnect, 100);
    lv_obj_set_height(buttonWifiConnect, 36);
    lv_obj_align(buttonWifiConnect, LV_ALIGN_BOTTOM_MID, 60, -14);
    lv_obj_set_style_bg_color(buttonWifiConnect, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_add_event_cb(buttonWifiConnect, [] (lv_event_t *event) {
        PageManager.p_push_black_fade("SYSTEM/HOME");
    }, LV_EVENT_CLICKED, nullptr);
    
    lv_obj_t *labelWifiConnect = lv_label_create(buttonWifiConnect);
    lv_label_set_text(labelWifiConnect, "CONNECT");
    lv_obj_set_style_text_color(labelWifiConnect, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_align(labelWifiConnect, LV_ALIGN_CENTER);

    lv_obj_t *buttonWifiCancel = lv_btn_create(root);
    lv_obj_set_width(buttonWifiCancel, 100);
    lv_obj_set_height(buttonWifiCancel, 36);
    lv_obj_set_style_border_width(buttonWifiCancel, 1, LV_PART_MAIN);
    lv_obj_set_style_border_color(buttonWifiCancel, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_align(buttonWifiCancel, LV_ALIGN_BOTTOM_MID, -60, -14);
    lv_obj_set_style_bg_color(buttonWifiCancel, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_add_event_cb(buttonWifiCancel, [] (lv_event_t *event) {
        PageManager.p_push("APP/WIFI_STATUS", PM_SCR_ANIM_MOVE_RIGHT);
    }, LV_EVENT_CLICKED, nullptr);
    
    lv_obj_t *labelWifiCancel = lv_label_create(buttonWifiCancel);
    lv_label_set_text(labelWifiCancel, "CANCEL");
    lv_obj_set_style_text_color(labelWifiCancel, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_align(labelWifiCancel, LV_ALIGN_CENTER);

    
    lv_group_add_obj(group, ssid_textarea);
    lv_group_add_obj(group, pwd_textarea);
    lv_group_add_obj(group, buttonWifiCancel);
    lv_group_add_obj(group, buttonWifiConnect);
}