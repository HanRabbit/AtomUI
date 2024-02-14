#include "translate.h"
#include "ui/components/status_bar/status_bar.h"
#include "ui/res/rp/rp.h"
#include "ui/utils/ui_utils.h"

extern StatusBar statusBar;

lv_obj_t *search_bar;
lv_obj_t *search_button;
lv_obj_t *search_panel;

void update_translate_status_bar(lv_timer_t *timer) {
    statusBar.status.title = "TRANSLATE";
    statusBar.update();
}

void search_bar_event(lv_event_t *e) {
    lv_event_code_t e_code = lv_event_get_code(e);
    switch (e_code) {
        case LV_EVENT_FOCUSED:
            search_box_spread_Animation(search_panel, 0);
            break;
        case LV_EVENT_DEFOCUSED:
            search_box_shrink_Animation(search_panel, 0);
            break;
        default:
            break;
    }
}

void create_search_box(lv_obj_t *root) {
    lv_disp_t * disp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(disp, lv_color_hex(0x040404), lv_color_hex(0x000000),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(disp, theme);

    search_panel = lv_obj_create(root);
    lv_obj_set_width(search_panel, 252);
    lv_obj_set_height(search_panel, 66);
    lv_obj_set_align(search_panel, LV_ALIGN_TOP_MID);
    lv_obj_set_pos(search_panel, 0, 20);
    lv_obj_set_flex_flow(search_panel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(search_panel, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_obj_clear_flag(search_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(search_panel, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(search_panel, 255, LV_PART_MAIN );
    lv_obj_set_style_border_width(search_panel, 0, LV_PART_MAIN);

    search_bar = lv_textarea_create(search_panel);
    lv_obj_set_width(search_bar, 220);
    lv_obj_set_height(search_bar, LV_SIZE_CONTENT);
    lv_textarea_set_placeholder_text(search_bar, "Search");
    lv_textarea_set_one_line(search_bar, true);
    lv_obj_add_event_cb(search_bar, search_bar_event, LV_EVENT_ALL, nullptr);
    lv_obj_set_style_outline_opa(search_bar, 0, LV_PART_MAIN);

    search_button = lv_btn_create(search_panel);
    lv_obj_set_width(search_button, 42);
    lv_obj_set_height(search_button, 36);
    lv_obj_set_align(search_button, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(search_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(search_button, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(search_button, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_bg_color(search_button, lv_color_hex(0xFAFAFA), LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(search_button, 255, LV_PART_MAIN);
    lv_obj_set_style_outline_opa(search_button, 0, LV_PART_MAIN);

    lv_obj_t *search_img = lv_img_create(search_button);
    lv_img_set_src(search_img, &ui_img_search_png);
    lv_obj_set_width(search_img, LV_SIZE_CONTENT);
    lv_obj_set_height(search_img, LV_SIZE_CONTENT);
    lv_obj_set_align(search_img, LV_ALIGN_CENTER);
    lv_obj_add_flag(search_img, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(search_img, LV_OBJ_FLAG_SCROLLABLE);

    lv_group_remove_all_objs(ui_group);
    lv_group_add_obj(ui_group, search_bar);
    lv_group_add_obj(ui_group, search_button);
    lv_group_add_obj(ui_group, statusBar.ui_back_button);
}

void scr_load_event(lv_event_t *e) {
    if (lv_event_get_code(e) == LV_EVENT_SCREEN_LOADED) {

    }
}

lv_obj_t *TranslatePage::page_create() {
    lv_obj_t *page_translate_scr = lv_obj_create(nullptr);
    lv_obj_set_style_bg_color(page_translate_scr, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_add_event_cb(page_translate_scr, scr_load_event, LV_EVENT_ALL, nullptr);

    statusBar.margin_y = 0;     /* 状态栏上方间距为0 */
    statusBar.create_status_bar(page_translate_scr);    /* 创建状态栏实例 */


    create_search_box(page_translate_scr);

    statusBar.status_bar_timer = lv_timer_create(update_translate_status_bar, STATUS_BAR_UPDATE_DURING, nullptr);

    return page_translate_scr;
}

lv_obj_t *TranslatePage::page_delete() {
    lv_timer_del(statusBar.status_bar_timer);
    free((int *) malloc(sizeof (int)));
    lv_obj_remove_event_cb(search_bar, nullptr);
    return nullptr;
}
