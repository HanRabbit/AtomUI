#ifndef ATOM_UI__TEMPLATE_H
#define ATOM_UI__TEMPLATE_H

#include <lvgl.h>

class TemplatePage {

public:
    static lv_obj_t *page_delete();

    static lv_obj_t *page_create();
};

#endif //ATOM_UI__TEMPLATE_H
