#include "_template.h"

lv_obj_t *TemplatePage::page_create() {
    lv_obj_t *page_startup_scr = lv_obj_create(nullptr);
    lv_obj_t *label = lv_label_create(page_startup_scr);
    lv_label_set_text(label, "Han!");
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    return page_startup_scr;
}

lv_obj_t *TemplatePage::page_delete() {
    return nullptr;
}
