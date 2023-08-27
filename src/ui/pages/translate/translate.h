#ifndef ATOM_UI_TRANSLATE_H
#define ATOM_UI_TRANSLATE_H

#include <lvgl.h>

class TranslatePage {
public:
    static lv_obj_t *page_create();

    static lv_obj_t *page_delete();
};

#endif //ATOM_UI_TRANSLATE_H
