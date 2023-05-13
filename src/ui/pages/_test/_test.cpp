#include "_test.h"

void TestPage::ui_event(lv_event_t *e) {
    lv_event_code_t e_code = lv_event_get_code(e);
    if (e_code == LV_EVENT_LONG_PRESSED) {
        Log::msg(LOG_NAME_DEFAULT, "Long Pressed");
    }
}

lv_obj_t *TestPage::page_create() {
    lv_obj_t *scr = lv_obj_create(nullptr);
    lv_obj_t *button = lv_btn_create(scr);
//    lv_label_set_text(button, "HELLO THERE.");
    lv_obj_set_align(button, LV_ALIGN_CENTER);

//    Log::msg("Long Pressed");

    lv_obj_add_event_cb(button, ui_event, LV_EVENT_ALL, nullptr);
//
    lv_group_t *group;
    lv_group_add_obj(group, scr);
//    lv_set_group(group);

    lv_group_set_default(group);
    lv_indev_set_group(lv_indev_drv_register(&indev_drv), group);

    return scr;
}

lv_obj_t *TestPage::page_delete() {
    return nullptr;
}
