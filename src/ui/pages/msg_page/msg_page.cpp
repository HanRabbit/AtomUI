#include "msg_page.h"

void label_event_get_cb(lv_event_t *e) {
    lv_obj_t *label = lv_event_get_target(e);
    lv_msg_t *m = lv_event_get_msg(e);
    lv_label_set_text(label, (const char *)lv_msg_get_payload(m));
}

lv_obj_t *MsgPage::page_create() {
    lv_obj_t *page_msg_scr = lv_obj_create(nullptr);

    lv_obj_t *label = lv_label_create(page_msg_scr);
    // lv_label_set_text(label, "Han!");
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(label, label_event_get_cb, LV_EVENT_MSG_RECEIVED, nullptr);
    lv_msg_subscribe_obj(0, label, nullptr);

    return page_msg_scr;
}

lv_obj_t *MsgPage::page_delete() {
    return nullptr;
}
