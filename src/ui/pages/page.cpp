#include "page.h"

void Page::p_init(const char *name, uint16_t id, lv_obj_t *(*create_func)(), lv_obj_t *(*delete_func)()) {
    p_create = create_func;
    p_delete = delete_func;
    p_name = name;
    p_id = id;
}

lv_obj_t *Page::p_load() {
    pageType = ready_showing;
    if (pageType == ready_showing) {
        pageType = showing;
    }
    return p_create();
}

//void Page::p_hide(lv_obj_t *scr) {
//    pageType = ready_hiding;
//    if (pageType == ready_hiding) {
//        pageType = hiding;
//        p_delete(scr);
//    }
//}
