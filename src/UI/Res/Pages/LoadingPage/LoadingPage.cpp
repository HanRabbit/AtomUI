#include "LoadingPage.h"
#include "UI/Res/ResourcePool/ResourcePool.h"
#include "UI/Themes/Themes.h"
#include "Common/TimerManager/TimerManager.h"
#include "UI/Utils/PageManager/PageManager.h"

lv_obj_t *loading_label;
lv_obj_t *loading_motion;

lv_obj_t *LoadingPage::create() {
    /* 先清除主屏幕上的组件 */
    lv_obj_clean(lv_scr_act());

    lv_obj_t *root;
    root = lv_obj_create(nullptr);
    lv_obj_remove_flag(root, LV_OBJ_FLAG_SCROLLABLE);

    loading_motion = lv_gif_create(root);
    lv_gif_set_src(loading_motion, LOADING_GIF_PATH);
    lv_obj_align(loading_motion, LV_ALIGN_CENTER, 0, -10);

    loading_label = lv_label_create(root);
    lv_label_set_text(loading_label, "LOADING");
    lv_obj_align(loading_label, LV_ALIGN_BOTTOM_MID, 0, 20);
    lv_obj_set_style_text_font(loading_label, &lv_font_montserrat_20, LV_PART_MAIN);

    /* 标签动画添加 */
    TimerManager.t_register([] (lv_timer_t *timer) {
        lv_anim_t *loading_anim = nullptr;
        lv_obj_add_anim(loading_label, loading_anim, [] (void *obj, int32_t y) {
            lv_obj_set_pos((lv_obj_t *) obj, 0, y);
        }, 20, -10, 400, nullptr, lv_anim_path_ease_out);
        lv_timer_delete(timer);
    }, 800, "LOADING_ANIM", nullptr, true);

    TimerManager.t_register([] (lv_timer_t *timer) {
        PageManager.p_push_black_fade("SYSTEM/HOME");
        lv_timer_delete(timer);
    }, 5000, "LOADING/HOME", nullptr, true);

    return root;
}

lv_obj_t *LoadingPage::del() {
    lv_obj_clean(loading_motion);
    return nullptr;
}