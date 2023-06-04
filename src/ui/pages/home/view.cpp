#include "view.h"

extern lv_obj_t *ui_wifi_icon, *ui_wifi_mode;
extern lv_obj_t *ui_root_panel, *ui_menu_panel;
extern lv_obj_t *ui_side_bar_panel, *ui_info_label;

extern lv_group_t *ui_group;

String APP_NAMES[20];
uint16_t apps_max_num = 0;

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

    lv_obj_t *ui_battery_perc_label = lv_label_create(ui_status_bar);
    lv_obj_set_width(ui_battery_perc_label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_battery_perc_label, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_battery_perc_label, -20);
    lv_obj_set_y(ui_battery_perc_label, 0);
    lv_obj_set_align(ui_battery_perc_label, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_battery_perc_label, "92%");
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

    lv_obj_t *ui_hour_min_panel = lv_obj_create(ui_time_panel);
    lv_obj_set_width(ui_hour_min_panel, 114);
    lv_obj_set_height(ui_hour_min_panel, 50);
    lv_obj_set_x(ui_hour_min_panel, 0);
    lv_obj_set_y(ui_hour_min_panel, -10);
    lv_obj_set_align(ui_hour_min_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_hour_min_panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_hour_min_panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_hour_min_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_hour_min_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_min_roller1 = lv_roller_create(ui_hour_min_panel);
    lv_roller_set_options(ui_min_roller1, "1\n2\n3\n4", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_min_roller1, 28);
    lv_obj_set_height(ui_min_roller1, 42);
    lv_obj_set_x(ui_min_roller1, 46);
    lv_obj_set_y(ui_min_roller1, 0);
    lv_obj_set_align(ui_min_roller1, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_min_roller1, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_min_roller1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_min_roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_min_roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_min_roller1, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_min_roller1, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_t *ui_min_roller2 = lv_roller_create(ui_hour_min_panel);
    lv_roller_set_options(ui_min_roller2, "1\n2\n3\n4", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_min_roller2, 28);
    lv_obj_set_height(ui_min_roller2, 42);
    lv_obj_set_x(ui_min_roller2, 20);
    lv_obj_set_y(ui_min_roller2, 0);
    lv_obj_set_align(ui_min_roller2, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_min_roller2, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_min_roller2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_min_roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_min_roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_min_roller2, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_min_roller2, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_t *ui_min_hour_dep_label = lv_label_create(ui_hour_min_panel);
    lv_obj_set_width(ui_min_hour_dep_label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_min_hour_dep_label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_min_hour_dep_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_min_hour_dep_label, ":");
    lv_obj_set_style_text_font(ui_min_hour_dep_label, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_hour_roller1 = lv_roller_create(ui_hour_min_panel);
    lv_roller_set_options(ui_hour_roller1, "1\n2\n3\n4", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_hour_roller1, 28);
    lv_obj_set_height(ui_hour_roller1, 42);
    lv_obj_set_x(ui_hour_roller1, -20);
    lv_obj_set_y(ui_hour_roller1, 0);
    lv_obj_set_align(ui_hour_roller1, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_hour_roller1, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_hour_roller1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_hour_roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_hour_roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_hour_roller1, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_hour_roller1, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_t *ui_hour_roller2 = lv_roller_create(ui_hour_min_panel);
    lv_roller_set_options(ui_hour_roller2, "1\n2\n3\n4", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_hour_roller2, 28);
    lv_obj_set_height(ui_hour_roller2, 42);
    lv_obj_set_x(ui_hour_roller2, -46);
    lv_obj_set_y(ui_hour_roller2, 0);
    lv_obj_set_align(ui_hour_roller2, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_hour_roller2, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_hour_roller2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_hour_roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_hour_roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_hour_roller2, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_hour_roller2, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);

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
    lv_obj_set_height(ui_side_bar_btn, 60);
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
    lv_obj_add_event_cb(ui_side_bar_btn, side_bar_button_event, LV_EVENT_ALL, nullptr);
    lv_obj_add_event_cb(ui_side_bar_btn, button_event, LV_EVENT_CLICKED, nullptr);

    lv_obj_t *ui_side_bar_btn_img = lv_img_create(ui_side_bar_btn);
    lv_img_set_src(ui_side_bar_btn_img, img_src);
    lv_obj_set_width(ui_side_bar_btn_img, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_side_bar_btn_img, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_side_bar_btn_img, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_side_bar_btn_img, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_side_bar_btn_img, LV_OBJ_FLAG_SCROLLABLE);

    lv_group_add_obj(ui_group, ui_side_bar_btn);
}

void home_ui_init(lv_obj_t *scr) {
    lv_set_theme();

    lv_obj_clear_flag(scr, LV_OBJ_FLAG_SCROLLABLE);

    create_root_panel(scr);
    create_status_bar(ui_menu_panel);
    create_time_panel(ui_menu_panel);
    create_side_bar_panel(ui_root_panel);

    HomeApp homeApp[10] {};
    homeApp[0].app_init("APPS", &ui_img_app_png, nullptr);
    homeApp[1].app_init("MENU", &ui_img_menu_png, nullptr);
    homeApp[2].app_init("POWER", &ui_img_power_2_png, nullptr);
    homeApp[3].app_init("SETTINGS", &ui_img_settings_png, nullptr);
}

void HomeApp::app_init(const char *app_name_, const void *icon_src_, lv_event_cb_t app_event_) {
    icon_src = icon_src_;
    app_name = app_name_;
    app_event = app_event_;
    app_id = apps_max_num;
    apps_max_num ++;

    APP_NAMES[app_id] = app_name;
    create_side_bar_button(icon_src, nullptr);
    lv_obj_update_snap(ui_side_bar_panel, LV_ANIM_ON);
}
