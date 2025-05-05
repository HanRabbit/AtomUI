#include "SideBar.h"
#include "UI/Utils/PageManager/PageManager.h"
#include "UI/Utils/UIGroup/UIGroup.h"
#include "UI/Themes/Themes.h"
#include "Common/TimerManager/TimerManager.h"

Side_Bar SideBar;

/**
 * @brief 创建侧边栏
 * @param root 侧边栏根部件
 */
void Side_Bar::init(lv_obj_t *root) {
    ui_side_bar = lv_obj_create(root);
    lv_obj_set_width(ui_side_bar, 36);
    lv_obj_set_height(ui_side_bar, 200);
    lv_obj_set_align(ui_side_bar, LV_ALIGN_CENTER);
    lv_obj_set_scrollbar_mode(ui_side_bar, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(ui_side_bar, LV_DIR_VER);
    lv_obj_set_flex_flow(ui_side_bar, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_side_bar, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_side_bar, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(ui_side_bar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_side_bar, lv_color_hex(SIDE_BAR_BG_COLOR), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(ui_side_bar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_side_bar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scroll_snap_y(ui_side_bar, LV_SCROLL_SNAP_CENTER);

    lv_obj_set_style_pad_left(ui_side_bar, 0, LV_PART_SCROLLBAR);
    lv_obj_set_style_pad_right(ui_side_bar, 0, LV_PART_SCROLLBAR);
    lv_obj_set_style_pad_top(ui_side_bar, 0, LV_PART_SCROLLBAR);
    lv_obj_set_style_pad_bottom(ui_side_bar, 0, LV_PART_SCROLLBAR);

    TimerManager.t_register([] (lv_timer_t *timer) {
        if (SideBar.side_bar_is_open) {
            lv_anim_t *anim;
            lv_obj_add_anim(static_cast<lv_obj_t *> (timer->user_data), anim, [] (void *e, int w) {
                lv_obj_set_width(SideBar.ui_side_bar, w);
            }, 36, 0, 400, nullptr, lv_anim_path_ease_out);
            SideBar.side_bar_is_open = false;
        }
    }, SIDE_BAR_BUTTON_COLLASPE_DURATION, "TIMER/SIDE_BAR_RESET", ui_side_bar, false);
}

/**
 * @brief 通过页面管理器推送页面
 * @param page_name 页面名称
 */
void push_page(lv_event_t *event) {
    auto *page_name = static_cast<const char *> (event -> user_data);
    /* 这里由于 ESP32-S3 算力有限，所以采用背光黑场渐变的转场方式 */
    PageManager.p_push_black_fade(page_name);
}

/**
 *
 * @param name 应用名称
 * @param page_name 页面名称
 * @param icon_path 应用图标路径
 */
void Side_Bar::add_button(const char *name, const char *page_name, const char *icon_path) {
    lv_obj_t *ui_side_bar_btn = lv_btn_create(ui_side_bar);
    lv_obj_set_width(ui_side_bar_btn, 36);
    lv_obj_set_height(ui_side_bar_btn, 46);
    lv_obj_set_x(ui_side_bar_btn, -10);
    lv_obj_set_y(ui_side_bar_btn, 0);
    lv_obj_set_align(ui_side_bar_btn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_side_bar_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_side_bar_btn, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui_side_bar_btn, LV_OBJ_FLAG_SNAPPABLE);
    lv_obj_set_style_radius(ui_side_bar_btn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_side_bar_btn, lv_color_hex(SIDE_BAR_BG_COLOR), LV_PART_MAIN);
    lv_obj_set_style_bg_color(ui_side_bar_btn, lv_color_hex(0x2A82E4), LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui_side_bar_btn, 255, LV_PART_MAIN);
    lv_obj_set_style_border_width(ui_side_bar_btn, 0, LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_side_bar_btn, 0, LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_side_bar_btn, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_column(ui_side_bar_btn, SIDE_BAR_BUTTON_COLUMN, LV_PART_MAIN);

    /* 添加页面跳转，当按下 Encoder 时，跳转页面 */
    lv_obj_add_event_cb(ui_side_bar_btn, push_page, LV_EVENT_RELEASED, const_cast<char *> (page_name));

    /* 添加按钮聚焦定时器重置事件 */
    lv_obj_add_event_cb(ui_side_bar_btn, [] (lv_event_t *event) {
        if (!SideBar.side_bar_is_open) {
            lv_anim_t *anim;
            lv_obj_add_anim(SideBar.ui_side_bar, anim, [] (void *e, int w) {
                lv_obj_set_width(SideBar.ui_side_bar, w);
            }, 0, 36, 400, nullptr, lv_anim_path_ease_out);
            SideBar.side_bar_is_open = true;
        }
        if (TimerManager.t_seek("TIMER/SIDE_BAR_RESET").timer != nullptr) {
            lv_timer_reset(TimerManager.t_seek("TIMER/SIDE_BAR_RESET").timer);
        }
        // LV_LOG_USER(TimerManager.t_seek("TIMER/SIDE_BAR_RESET").name);
    }, LV_EVENT_FOCUSED, ui_side_bar);

    lv_obj_t *ui_side_bar_btn_img = lv_img_create(ui_side_bar_btn);
    lv_img_set_src(ui_side_bar_btn_img, icon_path);
    lv_obj_set_width(ui_side_bar_btn_img, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_side_bar_btn_img, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_side_bar_btn_img, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_side_bar_btn_img, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_side_bar_btn_img, LV_OBJ_FLAG_SCROLLABLE);

    lv_set_no_out_line_theme();

    lv_group_add_obj(group, ui_side_bar_btn);
}


/**
 * @brief 获取侧边栏对象
 * @return 侧边栏对象
 */
lv_obj_t *Side_Bar::get_side_bar_obj() {
    return ui_side_bar;
}
