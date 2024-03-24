#include "wifi_config_view.h"

extern lv_group_t *ui_group;

void create_wifi_guide(lv_obj_t *root) {
    lv_obj_set_style_bg_color(root, lv_color_black(), LV_PART_MAIN);

    lv_obj_t *wifi_img = lv_img_create(root);
    lv_obj_align(wifi_img, LV_ALIGN_CENTER, 0, -40);
    lv_img_set_src(wifi_img, &wifi_b_img_png);

    lv_obj_t *tip_label = lv_label_create(root);
    lv_obj_align(tip_label, LV_ALIGN_CENTER, 0, 20);
    lv_label_set_text(tip_label, "To make your ATOM connect to wifi\n please input SSID and PASSWORD");
    lv_obj_align(tip_label, LV_ALIGN_CENTER, 0, 20);

    lv_obj_t *ok_button = lv_btn_create(root);
    lv_obj_set_style_bg_color(ok_button, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_align(ok_button, LV_ALIGN_CENTER, 0, 80);
    lv_obj_set_size(ok_button, 120, 30);

    lv_obj_t *ok_label = lv_label_create(ok_button);
    lv_obj_set_align(ok_label, LV_ALIGN_CENTER);
    lv_label_set_text(ok_label, "OK");
    lv_obj_set_style_text_color(ok_label, lv_color_black(), LV_PART_MAIN);

    lv_group_add_obj(ui_group, ok_button);
}