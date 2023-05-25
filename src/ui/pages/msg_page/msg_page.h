#ifndef ATOM_UI_MSG_PAGE_H
#define ATOM_UI_MSG_PAGE_H

#include <lvgl.h>

typedef lv_uintptr_t lv_msg_id_t;

class MsgPage {

public:
    static lv_obj_t *page_delete();

    static lv_obj_t *page_create();
};

#endif //ATOM_UI_MSG_PAGE_H
