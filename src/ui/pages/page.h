#ifndef ATOM_UI_PAGE_H
#define ATOM_UI_PAGE_H

#include <lvgl.h>

enum PageType {
    showing, hiding, ready_showing, ready_hiding
};

class Page {
public:
    const char *p_name{};     /* page name */
    uint16_t p_id{};      /* page id */
    lv_obj_t *(*p_create)(){};
    lv_obj_t *(*p_delete)(){};
    lv_obj_t *p_scr{};
    PageType pageType = hiding;

    void p_init(const char *name, uint16_t id, lv_obj_t *(*create_func)(), lv_obj_t *(*delete_func)());
    lv_obj_t *p_load();
//    void p_hide(lv_obj_t *scr);
};

#endif //ATOM_UI_PAGE_H
