// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.2.0
// Project name: atom_ui

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_Screen1;
lv_obj_t *ui_statusBar;
lv_obj_t *ui_wifiMode;
lv_obj_t *ui_wifiIcon;
lv_obj_t *ui_atomLabel;
lv_obj_t *ui_batteryIcon;
lv_obj_t *ui_Label1;
lv_obj_t *ui_timePanel;
lv_obj_t *ui_Bar2;
lv_obj_t *ui_timeLabel;
lv_obj_t *ui_Label2;
lv_obj_t *ui_Label3;
lv_obj_t *ui_Panel1;
lv_obj_t *ui_Image1;
lv_obj_t *ui_Label4;
lv_obj_t *ui_Image2;
lv_obj_t *ui_Label5;
lv_obj_t *ui_Image3;
lv_obj_t *ui_Label6;
lv_obj_t *ui_Image4;
lv_obj_t *ui_Label7;
lv_obj_t *ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_statusBar = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_statusBar, 320);
lv_obj_set_height( ui_statusBar, 18);
lv_obj_set_x( ui_statusBar, 0 );
lv_obj_set_y( ui_statusBar, 2 );
lv_obj_set_align( ui_statusBar, LV_ALIGN_TOP_MID );
lv_obj_clear_flag( ui_statusBar, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_statusBar, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_statusBar, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_statusBar, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_statusBar, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_wifiMode = lv_label_create(ui_statusBar);
lv_obj_set_width( ui_wifiMode, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_wifiMode, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_wifiMode, 20 );
lv_obj_set_y( ui_wifiMode, 0 );
lv_obj_set_align( ui_wifiMode, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_wifiMode,"STA");
lv_obj_set_style_text_font(ui_wifiMode, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_wifiIcon = lv_img_create(ui_statusBar);
lv_img_set_src(ui_wifiIcon, &ui_img_wifi_png);
lv_obj_set_width( ui_wifiIcon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_wifiIcon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_wifiIcon, LV_ALIGN_LEFT_MID );
lv_obj_add_flag( ui_wifiIcon, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_wifiIcon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_atomLabel = lv_label_create(ui_statusBar);
lv_obj_set_width( ui_atomLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_atomLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_atomLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_atomLabel,"ATOM");
lv_obj_set_style_text_font(ui_atomLabel, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_batteryIcon = lv_img_create(ui_statusBar);
lv_img_set_src(ui_batteryIcon, &ui_img_battery_png);
lv_obj_set_width( ui_batteryIcon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_batteryIcon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_batteryIcon, LV_ALIGN_RIGHT_MID );
lv_obj_add_flag( ui_batteryIcon, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_batteryIcon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label1 = lv_label_create(ui_statusBar);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1, -20 );
lv_obj_set_y( ui_Label1, 0 );
lv_obj_set_align( ui_Label1, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_Label1,"92%");
lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_timePanel = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_timePanel, 170);
lv_obj_set_height( ui_timePanel, 96);
lv_obj_set_x( ui_timePanel, 0 );
lv_obj_set_y( ui_timePanel, -10 );
lv_obj_set_align( ui_timePanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_timePanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_timePanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_timePanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_timePanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Bar2 = lv_bar_create(ui_timePanel);
lv_bar_set_value(ui_Bar2,100,LV_ANIM_OFF);
lv_obj_set_width( ui_Bar2, 140);
lv_obj_set_height( ui_Bar2, 3);
lv_obj_set_x( ui_Bar2, 0 );
lv_obj_set_y( ui_Bar2, 10 );
lv_obj_set_align( ui_Bar2, LV_ALIGN_CENTER );

lv_obj_set_style_bg_color(ui_Bar2, lv_color_hex(0x2A82E4), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Bar2, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

ui_timeLabel = lv_label_create(ui_timePanel);
lv_obj_set_width( ui_timeLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_timeLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_timeLabel, 0 );
lv_obj_set_y( ui_timeLabel, -16 );
lv_obj_set_align( ui_timeLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_timeLabel,"13:01");
lv_obj_set_style_text_letter_space(ui_timeLabel, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_timeLabel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_timeLabel, &lv_font_montserrat_40, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label2 = lv_label_create(ui_timePanel);
lv_obj_set_width( ui_Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label2, LV_ALIGN_BOTTOM_LEFT );
lv_label_set_text(ui_Label2,"Wed");
lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label3 = lv_label_create(ui_timePanel);
lv_obj_set_width( ui_Label3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label3, LV_ALIGN_BOTTOM_RIGHT );
lv_label_set_text(ui_Label3,"2023-4-15");
lv_obj_set_style_text_letter_space(ui_Label3, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Label3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel1 = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_Panel1, 300);
lv_obj_set_height( ui_Panel1, 66);
lv_obj_set_x( ui_Panel1, 0 );
lv_obj_set_y( ui_Panel1, 80 );
lv_obj_set_align( ui_Panel1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image1 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image1, &ui_img_link_png);
lv_obj_set_width( ui_Image1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image1, LV_SIZE_CONTENT);   /// 1
lv_obj_add_flag( ui_Image1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label4 = lv_label_create(ui_Panel1);
lv_obj_set_width( ui_Label4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4, 26 );
lv_obj_set_y( ui_Label4, 3 );
lv_label_set_text(ui_Label4,"PING: 45ms");
lv_obj_set_style_text_letter_space(ui_Label4, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Label4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label4, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image2 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image2, &ui_img_time_png);
lv_obj_set_width( ui_Image2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image2, -92 );
lv_obj_set_y( ui_Image2, 0 );
lv_obj_set_align( ui_Image2, LV_ALIGN_TOP_RIGHT );
lv_obj_add_flag( ui_Image2, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label5 = lv_label_create(ui_Panel1);
lv_obj_set_width( ui_Label5, 86);
lv_obj_set_height( ui_Label5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label5, 0 );
lv_obj_set_y( ui_Label5, 2 );
lv_obj_set_align( ui_Label5, LV_ALIGN_TOP_RIGHT );
lv_label_set_text(ui_Label5,"START: 40s");
lv_obj_set_style_text_letter_space(ui_Label5, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Label5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Label5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label5, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image3 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image3, &ui_img_follows_png);
lv_obj_set_width( ui_Image3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Image3, LV_ALIGN_BOTTOM_LEFT );
lv_obj_add_flag( ui_Image3, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label6 = lv_label_create(ui_Panel1);
lv_obj_set_width( ui_Label6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label6, 26 );
lv_obj_set_y( ui_Label6, 0 );
lv_obj_set_align( ui_Label6, LV_ALIGN_BOTTOM_LEFT );
lv_label_set_text(ui_Label6,"FOLLOWS: 45");
lv_obj_set_style_text_letter_space(ui_Label6, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Label6, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label6, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image4 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image4, &ui_img_follows_png);
lv_obj_set_width( ui_Image4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image4, -92 );
lv_obj_set_y( ui_Image4, 0 );
lv_obj_set_align( ui_Image4, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_Image4, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label7 = lv_label_create(ui_Panel1);
lv_obj_set_width( ui_Label7, 86);
lv_obj_set_height( ui_Label7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label7, LV_ALIGN_BOTTOM_RIGHT );
lv_label_set_text(ui_Label7,"APPS: 8");
lv_obj_set_style_text_letter_space(ui_Label7, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Label7, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Label7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label7, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

}

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_Screen1_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_Screen1);
}
