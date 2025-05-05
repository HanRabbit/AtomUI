#ifndef ATOM_UI_LV9_TEST_PAGE_H
#define ATOM_UI_LV9_TEST_PAGE_H

#include <lvgl.h>

struct TestPage {
    static lv_obj_t *create();
    static lv_obj_t *del();
};

#endif // ATOM_UI_LV9_TEST_PAGE_H
