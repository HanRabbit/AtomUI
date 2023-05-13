#ifndef ATOM_UI_ERROR_H
#define ATOM_UI_ERROR_H

#include <lvgl.h>

class ErrorPage {

public:

    static lv_obj_t *page_delete();

    static lv_obj_t *page_create();
};

#endif //ATOM_UI_ERROR_H
