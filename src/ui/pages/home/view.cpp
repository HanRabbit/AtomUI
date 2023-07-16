#include "view.h"

extern lv_obj_t *ui_wifi_icon, *ui_wifi_mode;
extern lv_obj_t *ui_root_panel, *ui_menu_panel;
extern lv_obj_t *ui_side_bar_panel, *ui_info_label;
extern lv_obj_t *ui_hour_min_label;
extern lv_obj_t *ui_battery_perc_label;

extern lv_group_t *ui_group;

extern void side_bar_button_event(lv_event_t *e);

void lv_set_theme() {
    lv_disp_t * disp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_NONE), lv_palette_main(LV_PALETTE_BLUE),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(disp, theme);
}

void create_status_bar(lv_obj_t *root) {
    lv_obj_t *ui_status_bar = lv_obj_create(root);
    lv_obj_set_width(ui_status_bar, 320);
    lv_obj_set_height(ui_status_bar, 18);
    lv_obj_set_x(ui_status_bar, 0);
    lv_obj_set_y(ui_status_bar, -10);
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

    lv_obj_t *ui_battery_icon = lv_img_create(ui_status_bar);
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

void create_time_panel(lv_obj_t *root) {
    lv_obj_t *ui_time_panel = lv_obj_create(root);
    lv_obj_set_width(ui_time_panel, 170);
    lv_obj_set_height(ui_time_panel, 96);
    lv_obj_set_x(ui_time_panel, 0);
    lv_obj_set_y(ui_time_panel, -12);
    lv_obj_set_align(ui_time_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_time_panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_time_panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_time_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_time_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_hour_min_label = lv_label_create(ui_time_panel);
    lv_obj_set_x(ui_hour_min_label, 0);
    lv_obj_set_y(ui_hour_min_label, -10);
    lv_obj_set_align(ui_hour_min_label, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_hour_min_label, &lv_font_montserrat_40, 0);
    lv_label_set_text(ui_hour_min_label, "--:--");
    lv_obj_set_style_text_letter_space(ui_hour_min_label, 4, 0);

    lv_obj_t *ui_time_bar = lv_bar_create(ui_time_panel);
    lv_bar_set_value(ui_time_bar, 100, LV_ANIM_OFF);
    lv_obj_set_width(ui_time_bar, 140);
    lv_obj_set_height(ui_time_bar, 3);
    lv_obj_set_x(ui_time_bar, 0);
    lv_obj_set_y(ui_time_bar, 16);
    lv_obj_set_align(ui_time_bar, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_time_bar, lv_color_hex(0x2A82E4), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_time_bar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
}

void create_root_panel(lv_obj_t *root) {
    ui_root_panel = lv_obj_create(root);
    lv_obj_set_width(ui_root_panel, lv_pct(100));
    lv_obj_set_height(ui_root_panel, lv_pct(100));
    lv_obj_set_y(ui_root_panel, 0);
    lv_obj_set_x(ui_root_panel, lv_pct(0));
    lv_obj_set_align(ui_root_panel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_root_panel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_root_panel, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_root_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(ui_root_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_root_panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_root_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_root_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_root_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_root_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_root_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_root_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_menu_panel = lv_obj_create(ui_root_panel);
    lv_obj_set_width(ui_menu_panel, lv_pct(100));
    lv_obj_set_height(ui_menu_panel, lv_pct(100));
    lv_obj_set_align(ui_menu_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_menu_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(ui_menu_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_menu_panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_menu_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_menu_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_menu_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void create_side_bar_panel(lv_obj_t *root) {
    ui_side_bar_panel = lv_obj_create(root);
    lv_obj_set_width(ui_side_bar_panel, 36);
    lv_obj_set_height(ui_side_bar_panel, 200);
    lv_obj_set_align(ui_side_bar_panel, LV_ALIGN_CENTER);
    lv_obj_set_scrollbar_mode(ui_side_bar_panel, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(ui_side_bar_panel, LV_DIR_VER);
    lv_obj_set_flex_flow(ui_side_bar_panel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_side_bar_panel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_side_bar_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(ui_side_bar_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_side_bar_panel, lv_color_hex(HOME_SIDE_BAR_BG_COLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_side_bar_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_side_bar_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scroll_snap_y(ui_side_bar_panel, LV_SCROLL_SNAP_CENTER);

    lv_obj_set_style_pad_left(ui_side_bar_panel, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_side_bar_panel, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_side_bar_panel, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_side_bar_panel, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
}

void create_side_bar_button(const void *img_src, lv_event_cb_t button_event) {
    lv_obj_t *ui_side_bar_btn;
    ui_side_bar_btn = lv_btn_create(ui_side_bar_panel);
    lv_obj_set_width(ui_side_bar_btn, 36);
    lv_obj_set_height(ui_side_bar_btn, 46);
    lv_obj_set_x(ui_side_bar_btn, -10);
    lv_obj_set_y(ui_side_bar_btn, 0);
    lv_obj_set_align(ui_side_bar_btn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_side_bar_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_side_bar_btn, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui_side_bar_btn, LV_OBJ_FLAG_SNAPABLE);
    lv_obj_set_style_radius(ui_side_bar_btn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_side_bar_btn, lv_color_hex(HOME_SIDE_BAR_BG_COLOR), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_side_bar_btn, lv_color_hex(0x2A82E4), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui_side_bar_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_side_bar_btn, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_pad_column(ui_side_bar_btn, HOME_SIDE_BAR_BUTTON_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_side_bar_btn, button_event, LV_EVENT_CLICKED, nullptr);
    lv_obj_add_event_cb(ui_side_bar_btn, side_bar_button_event, LV_EVENT_ALL, nullptr);

    lv_obj_t *ui_side_bar_btn_img = lv_img_create(ui_side_bar_btn);
    lv_img_set_src(ui_side_bar_btn_img, img_src);
    lv_obj_set_width(ui_side_bar_btn_img, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_side_bar_btn_img, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_side_bar_btn_img, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_side_bar_btn_img, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_side_bar_btn_img, LV_OBJ_FLAG_SCROLLABLE);

    lv_group_add_obj(ui_group, ui_side_bar_btn);
}

void create_info_panel(lv_obj_t *root) {
    lv_obj_t *ui_info_panel = lv_obj_create(root);
    lv_obj_set_width(ui_info_panel, 300);
    lv_obj_set_height(ui_info_panel, 66);
    lv_obj_set_x(ui_info_panel, 0 );
    lv_obj_set_y(ui_info_panel, 80 );
    lv_obj_set_align(ui_info_panel, LV_ALIGN_CENTER );
    lv_obj_clear_flag(ui_info_panel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(ui_info_panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_opa(ui_info_panel, 255, 0);
    lv_obj_set_style_border_width(ui_info_panel, 0, 0);

    lv_obj_t *ui_link_img = lv_img_create(ui_info_panel);
    lv_img_set_src(ui_link_img, &ui_img_link_png);
    lv_obj_set_width(ui_link_img, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_link_img, LV_SIZE_CONTENT);   /// 1
    lv_obj_add_flag(ui_link_img, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
    lv_obj_clear_flag(ui_link_img, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

    lv_obj_t *ui_info_ping_label = lv_label_create(ui_info_panel);
    lv_obj_set_width( ui_info_ping_label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_info_ping_label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x( ui_info_ping_label, 26 );
    lv_obj_set_y( ui_info_ping_label, 3 );
    lv_label_set_text(ui_info_ping_label,"PING: 45ms");
    lv_obj_set_style_text_letter_space(ui_info_ping_label, 2, 0);
    lv_obj_set_style_text_line_space(ui_info_ping_label, 0, 0);
    lv_obj_set_style_text_font(ui_info_ping_label, &lv_font_montserrat_12, 0);

    lv_obj_t *ui_time_img = lv_img_create(ui_info_panel);
    lv_img_set_src(ui_time_img, &ui_img_time_png);
    lv_obj_set_width( ui_time_img, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_time_img, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x( ui_time_img, -92 );
    lv_obj_set_y( ui_time_img, 0 );
    lv_obj_set_align( ui_time_img, LV_ALIGN_TOP_RIGHT );
    lv_obj_add_flag( ui_time_img, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
    lv_obj_clear_flag( ui_time_img, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

    lv_obj_t *ui_start_time_label = lv_label_create(ui_info_panel);
    lv_obj_set_width( ui_start_time_label, 86);
    lv_obj_set_height( ui_start_time_label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x( ui_start_time_label, 0 );
    lv_obj_set_y( ui_start_time_label, 2 );
    lv_obj_set_align( ui_start_time_label, LV_ALIGN_TOP_RIGHT );
    lv_label_set_text(ui_start_time_label,"START: 40s");
    lv_obj_set_style_text_letter_space(ui_start_time_label, 2, 0);
    lv_obj_set_style_text_line_space(ui_start_time_label, 0, 0);
    lv_obj_set_style_text_align(ui_start_time_label, LV_TEXT_ALIGN_LEFT, 0);
    lv_obj_set_style_text_font(ui_start_time_label, &lv_font_montserrat_12, 0);

    lv_obj_t *ui_follows_img = lv_img_create(ui_info_panel);
    lv_img_set_src(ui_follows_img, &ui_img_follows_png);
    lv_obj_set_width( ui_follows_img, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_follows_img, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align( ui_follows_img, LV_ALIGN_BOTTOM_LEFT );
    lv_obj_add_flag( ui_follows_img, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
    lv_obj_clear_flag( ui_follows_img, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

    lv_obj_t *ui_follows_label = lv_label_create(ui_info_panel);
    lv_obj_set_width( ui_follows_label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_follows_label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x( ui_follows_label, 26 );
    lv_obj_set_y( ui_follows_label, 0 );
    lv_obj_set_align( ui_follows_label, LV_ALIGN_BOTTOM_LEFT );
    lv_label_set_text(ui_follows_label,"FOLLOWS: 45");
    lv_obj_set_style_text_letter_space(ui_follows_label, 2, 0);
    lv_obj_set_style_text_line_space(ui_follows_label, 0, 0);
    lv_obj_set_style_text_font(ui_follows_label, &lv_font_montserrat_12, 0);

    lv_obj_t *ui_apps_img = lv_img_create(ui_info_panel);
    lv_img_set_src(ui_apps_img, &ui_img_follows_png);
    lv_obj_set_width( ui_apps_img, LV_SIZE_CONTENT);
    lv_obj_set_height( ui_apps_img, LV_SIZE_CONTENT);
    lv_obj_set_x( ui_apps_img, -92 );
    lv_obj_set_y( ui_apps_img, 0 );
    lv_obj_set_align( ui_apps_img, LV_ALIGN_BOTTOM_RIGHT );
    lv_obj_add_flag( ui_apps_img, LV_OBJ_FLAG_ADV_HITTEST );
    lv_obj_clear_flag( ui_apps_img, LV_OBJ_FLAG_SCROLLABLE );

    lv_obj_t *ui_info_apps_label = lv_label_create(ui_info_panel);
    lv_obj_set_width( ui_info_apps_label, 86);
    lv_obj_set_height( ui_info_apps_label, LV_SIZE_CONTENT);
    lv_obj_set_align( ui_info_apps_label, LV_ALIGN_BOTTOM_RIGHT );
    lv_label_set_text(ui_info_apps_label,"APPS: 8");
    lv_obj_set_style_text_letter_space(ui_info_apps_label, 2, 0);
    lv_obj_set_style_text_line_space(ui_info_apps_label, 0, 0);
    lv_obj_set_style_text_align(ui_info_apps_label, LV_TEXT_ALIGN_LEFT, 0);
    lv_obj_set_style_text_font(ui_info_apps_label, &lv_font_montserrat_12, 0);
}

void home_ui_init(lv_obj_t *scr) {
    lv_set_theme();

    lv_obj_clear_flag(scr, LV_OBJ_FLAG_SCROLLABLE);

    create_root_panel(scr);
    create_status_bar(ui_menu_panel);
    create_time_panel(ui_menu_panel);
    create_info_panel(ui_menu_panel);
    create_side_bar_panel(ui_root_panel);
}
