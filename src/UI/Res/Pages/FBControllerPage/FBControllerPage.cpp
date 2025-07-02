#include "FBControllerPage.h"
#include "UI/Res/Components/StatusBar/StatusBar.h"
#include "Common/MessageManager/Account.h"
#include "UI/Utils/UIGroup/UIGroup.h"
#include "UI/Themes/Themes.h"

lv_obj_t *FBControllerPage::create() {
    lv_obj_t *root = lv_obj_create(nullptr);
    StatusBar.create(root);

    /* 发布 APP 标题名称消息 */
    publisher.publish(MSG_ID_SYSTEM_APP_TITLE, FB_CONTROLLER_PAGE_NAME);

    lv_set_default_theme();

    lv_obj_t *ui_Panel4 = lv_obj_create(root);
    lv_obj_set_width( ui_Panel4, 116);
    lv_obj_set_height( ui_Panel4, 174);
    lv_obj_set_x( ui_Panel4, 20 );
    lv_obj_set_y( ui_Panel4, 14 );
    lv_obj_set_align( ui_Panel4, LV_ALIGN_LEFT_MID );
    lv_obj_set_flex_flow(ui_Panel4,LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_Panel4, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_obj_clear_flag( ui_Panel4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_opa(ui_Panel4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

    lv_obj_t *ui_Label22 = lv_label_create(ui_Panel4);
    lv_obj_set_width( ui_Label22, lv_pct(102));
    lv_obj_set_height( ui_Label22, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align( ui_Label22, LV_ALIGN_TOP_MID );
    lv_label_set_text(ui_Label22,"PID Parameters");
    lv_obj_set_style_text_align(ui_Label22, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

    lv_obj_t *ui_Container1 = lv_obj_create(ui_Panel4);
    lv_obj_remove_style_all(ui_Container1);
    lv_obj_set_height( ui_Container1, 46);
    lv_obj_set_width( ui_Container1, lv_pct(100));
    lv_obj_set_align( ui_Container1, LV_ALIGN_CENTER );
    lv_obj_clear_flag( ui_Container1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

    lv_obj_t *ui_Spinbox3 = lv_spinbox_create(ui_Container1);
    lv_obj_set_width( ui_Spinbox3, 80);
    lv_obj_set_height( ui_Spinbox3, 36);
    lv_obj_align( ui_Spinbox3, LV_ALIGN_RIGHT_MID, -4, 0);
    lv_spinbox_set_digit_format( ui_Spinbox3, 4, 2);
    lv_spinbox_set_range( ui_Spinbox3, 0,9999 );
    lv_spinbox_set_cursor_pos(ui_Spinbox3, 1 - 1);

    lv_obj_t *ui_Label24 = lv_label_create(ui_Container1);
    lv_obj_set_width( ui_Label24, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_Label24, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x( ui_Label24, 10 );
    lv_obj_set_y( ui_Label24, -2 );
    lv_obj_set_align( ui_Label24, LV_ALIGN_LEFT_MID );
    lv_label_set_text(ui_Label24,"P");

    lv_obj_t *ui_Container2 = lv_obj_create(ui_Panel4);
    lv_obj_remove_style_all(ui_Container2);
    lv_obj_set_height( ui_Container2, 46);
    lv_obj_set_width( ui_Container2, lv_pct(100));
    lv_obj_set_align( ui_Container2, LV_ALIGN_CENTER );
    lv_obj_clear_flag( ui_Container2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

    lv_obj_t *ui_Spinbox1 = lv_spinbox_create(ui_Container2);
    lv_obj_set_width( ui_Spinbox1, 80);
    lv_obj_set_height( ui_Spinbox1, 36);
    lv_obj_align( ui_Spinbox1, LV_ALIGN_RIGHT_MID, -4, 0);
    lv_spinbox_set_digit_format( ui_Spinbox1, 4, 2);
    lv_spinbox_set_range( ui_Spinbox1, 0,9999 );
    lv_spinbox_set_cursor_pos(ui_Spinbox1, 1 - 1);

    lv_obj_t *ui_Label25 = lv_label_create(ui_Container2);
    lv_obj_set_width( ui_Label25, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_Label25, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x( ui_Label25, 10 );
    lv_obj_set_y( ui_Label25, -2 );
    lv_obj_set_align( ui_Label25, LV_ALIGN_LEFT_MID );
    lv_label_set_text(ui_Label25,"I");

    lv_obj_t *ui_Container3 = lv_obj_create(ui_Panel4);
    lv_obj_remove_style_all(ui_Container3);
    lv_obj_set_height( ui_Container3, 46);
    lv_obj_set_width( ui_Container3, lv_pct(100));
    lv_obj_set_align( ui_Container3, LV_ALIGN_CENTER );
    lv_obj_clear_flag( ui_Container3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

    lv_obj_t *ui_Spinbox2 = lv_spinbox_create(ui_Container3);
    lv_obj_set_width( ui_Spinbox2, 80);
    lv_obj_set_height( ui_Spinbox2, 36);
    lv_obj_align( ui_Spinbox2, LV_ALIGN_RIGHT_MID, -4, 0);
    lv_spinbox_set_digit_format( ui_Spinbox2, 4, 2);
    lv_spinbox_set_range( ui_Spinbox2, 0,9999 );
    lv_spinbox_set_cursor_pos(ui_Spinbox2, 1 - 1);

    lv_obj_t *ui_Label26 = lv_label_create(ui_Container3);
    lv_obj_set_width( ui_Label26, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_Label26, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x( ui_Label26, 10 );
    lv_obj_set_y( ui_Label26, -2 );
    lv_obj_set_align( ui_Label26, LV_ALIGN_LEFT_MID );
    lv_label_set_text(ui_Label26,"D");

    lv_obj_t *ui_Button1 = lv_btn_create(root);
    lv_obj_set_width( ui_Button1, 140);
    lv_obj_set_height( ui_Button1, 36);
    lv_obj_set_x( ui_Button1, -20 );
    lv_obj_set_y( ui_Button1, -23 );
    lv_obj_set_align( ui_Button1, LV_ALIGN_BOTTOM_RIGHT );
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button1, lv_color_hex(0xFFFFFF), LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_Button1, 2, LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_Button1, 3, LV_STATE_FOCUSED);

    lv_obj_t *ui_Label27 = lv_label_create(ui_Button1);
    lv_obj_set_width( ui_Label27, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_Label27, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align( ui_Label27, LV_ALIGN_CENTER );
    lv_label_set_text(ui_Label27,"START");
    lv_obj_set_style_text_color(ui_Label27, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_text_opa(ui_Label27, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

    lv_obj_t *ui_Dropdown2 = lv_dropdown_create(root);
    lv_dropdown_set_options( ui_Dropdown2, "Position\nTrack\nTrace" );
    lv_obj_set_width( ui_Dropdown2, 140);
    lv_obj_set_height( ui_Dropdown2, 36);
    lv_obj_set_x( ui_Dropdown2, -20 );
    lv_obj_set_y( ui_Dropdown2, -25 );
    lv_obj_set_align( ui_Dropdown2, LV_ALIGN_RIGHT_MID );
    lv_obj_add_flag( ui_Dropdown2, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
    lv_obj_set_style_outline_color(ui_Dropdown2, lv_color_hex(0xFFFFFF), LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_Dropdown2, 2, LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_Dropdown2, 3, LV_STATE_FOCUSED);

    lv_obj_t *ui_Label28 = lv_label_create(root);
    lv_obj_set_width( ui_Label28, 130);
    lv_obj_set_height( ui_Label28, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x( ui_Label28, -26 );
    lv_obj_set_y( ui_Label28, -64 );
    lv_obj_set_align( ui_Label28, LV_ALIGN_RIGHT_MID );
    lv_label_set_text(ui_Label28,"Motion Type");

    lv_obj_t *ui_Button3 = lv_btn_create(root);
    lv_obj_set_width( ui_Button3, 140);
    lv_obj_set_height( ui_Button3, 36);
    lv_obj_set_x( ui_Button3, -20 );
    lv_obj_set_y( ui_Button3, 28 );
    lv_obj_set_align( ui_Button3, LV_ALIGN_RIGHT_MID );
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Button3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_border_opa(ui_Button3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Button3, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button3, lv_color_hex(0xFFFFFF), LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_Button3, 2, LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_Button3, 3, LV_STATE_FOCUSED);

    lv_obj_t *ui_Label29 = lv_label_create(ui_Button3);
    lv_obj_set_width( ui_Label29, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_Label29, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align( ui_Label29, LV_ALIGN_CENTER );
    lv_label_set_text(ui_Label29,"SERVO SETTINGS");


    /* 将返回按钮添加到当前操作组 */
    lv_group_add_obj(group, ui_Spinbox3);
    lv_group_add_obj(group, ui_Spinbox1);
    lv_group_add_obj(group, ui_Spinbox2);
    lv_group_add_obj(group, ui_Dropdown2);
    lv_group_add_obj(group, ui_Button3);
    lv_group_add_obj(group, ui_Button1);
    lv_group_add_obj(group, StatusBar.back_button);

    return root;
}

lv_obj_t *FBControllerPage::del() {
    // lv_obj_clean(root);
    return nullptr;
}