#include "LaunchPage.h"
#include "UI/Res/ResourcePool/ResourcePool.h"
#include "UI/Utils/PageManager/PageManager.h"
#include "Common/TimerManager/TimerManager.h"

lv_obj_t *progress_bar;

lv_obj_t *LaunchPage::create() {
    /* 主屏幕创建 */
    lv_obj_t *root;
    root = lv_obj_create(nullptr);
    lv_obj_set_style_bg_color(root, lv_color_black(), LV_PART_MAIN);

    /* Atom Logo */
    lv_obj_t *atom_img = lv_image_create(root);
    lv_image_set_src(atom_img, ATOM_LOGO_IMG_PATH);
    lv_obj_align(atom_img, LV_ALIGN_CENTER, 0, -8);

    /* Progress Bar */
    progress_bar = lv_bar_create(root);
    lv_obj_set_style_size(progress_bar, 100, 5, LV_PART_MAIN);
    lv_obj_align(progress_bar, LV_ALIGN_CENTER, 0, 20);
    lv_bar_set_range(progress_bar, 0, 101);
    lv_obj_set_style_anim_duration(progress_bar, 2000, LV_PART_MAIN);

    TimerManager.t_register([] (lv_timer_t *timer) {
        lv_bar_set_value(progress_bar, 100, LV_ANIM_ON);
        lv_timer_delete(timer);
    }, 800, "LAUNCH/PROGRESS_BAR", nullptr, true);

    TimerManager.t_register([] (lv_timer_t *timer) {
        PageManager.p_push_black_fade("SYSTEM/HOME");
        lv_timer_delete(timer);
    }, 3400, "LAUNCH/HOME", nullptr, true);

    return root;
}

lv_obj_t *LaunchPage::del() {
    return nullptr;
}
