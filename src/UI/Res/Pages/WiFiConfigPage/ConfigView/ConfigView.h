#ifndef ATOM_UI_LV9_CONFIG_VIEW_H
#define ATOM_UI_LV9_CONFIG_VIEW_H

#include "lvgl.h"

class ConfigViewPage {
public:
    static void createRootView(lv_obj_t *root);
    static lv_obj_t *create();
    static lv_obj_t *del();
};

#endif // ATOM_UI_LV9_CONFIG_VIEW_H