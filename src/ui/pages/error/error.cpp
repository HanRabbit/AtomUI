#include "error.h"

lv_obj_t *ErrorPage::page_create() {
    lv_obj_t *scr, *error_panel, *error_face_label, *error_label, *error_detail_label, *error_describe_label;

    scr = lv_obj_create(nullptr);
    lv_obj_clear_flag(scr, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x2A82E4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(scr, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    error_panel = lv_obj_create(scr);
    lv_obj_set_width(error_panel, 300);
    lv_obj_set_height(error_panel, 100);
    lv_obj_set_x(error_panel, 0);
    lv_obj_set_y(error_panel, 30);
    lv_obj_set_align(error_panel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(error_panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(error_panel, lv_color_hex(0x2A82E4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(error_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(error_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    error_face_label = lv_label_create(error_panel);
    lv_obj_set_width(error_face_label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(error_face_label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(error_face_label, LV_ALIGN_LEFT_MID);
    lv_label_set_text(error_face_label, ": (");
    lv_obj_set_style_text_font(error_face_label, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    error_label = lv_label_create(error_panel);
    lv_obj_set_width(error_label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(error_label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(error_label, -36);
    lv_obj_set_y(error_label, 0);
    lv_obj_set_align(error_label, LV_ALIGN_TOP_MID);
    lv_label_set_text(error_label, "ERROR!");
    lv_obj_set_style_text_font(error_label, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    error_detail_label = lv_label_create(error_panel);
    lv_obj_set_width(error_detail_label, 200);   /// 1
    lv_obj_set_height(error_detail_label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(error_detail_label, -20);
    lv_obj_set_align(error_detail_label, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_text(error_detail_label, "We faced a problem on your ATOM");

    error_describe_label = lv_label_create(scr);
    lv_obj_set_width(error_describe_label, 280);
    lv_obj_set_height(error_describe_label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(error_describe_label, 0);
    lv_obj_set_y(error_describe_label, 60);
    lv_obj_set_align(error_describe_label, LV_ALIGN_CENTER);
    lv_label_set_text(error_describe_label, "error code [ 21 ]: Please insert your SD/micro SD card");
    lv_obj_set_style_text_align(error_describe_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    return scr;
}

lv_obj_t *ErrorPage::page_delete() {
    return nullptr;
}
