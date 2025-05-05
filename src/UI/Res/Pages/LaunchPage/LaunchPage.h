#ifndef ATOM_UI_LV9_START_PAGE_H
#define ATOM_UI_LV9_START_PAGE_H

#include <Arduino.h>
#include <lvgl.h>

struct LaunchPage {
    static lv_obj_t *create();
    static lv_obj_t *del();
};

#endif // ATOM_UI_LV9_START_PAGE_H
