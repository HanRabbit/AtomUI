#ifndef ATOM_UI_LV9_FB_CONTROLLER_PAGE_H
#define ATOM_UI_LV9_FB_CONTROLLER_PAGE_H

#include "lvgl.h"

#define FB_CONTROLLER_PAGE_NAME "Flex-Ball Controller"

class FBControllerPage {
public:
    static lv_obj_t *create();
    static lv_obj_t *del();
};

#endif // ATOM_UI_LV9_FB_CONTROLLER_PAGE_H
