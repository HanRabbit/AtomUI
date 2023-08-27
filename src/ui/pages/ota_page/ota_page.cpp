#include "ota_page.h"

void OTAPage::ui_event(lv_event_t *e) {
    lv_event_code_t e_code = lv_event_get_code(e);

}

lv_obj_t *OTAPage::page_create() {
    lv_obj_t *scr = lv_obj_create(nullptr);
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x000000), LV_PART_MAIN);



    return scr;
}

lv_obj_t *OTAPage::page_delete() {
    return nullptr;
}
