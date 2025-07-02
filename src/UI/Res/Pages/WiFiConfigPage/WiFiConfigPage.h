#ifndef ATOM_UI_LV9_WIFI_CONFIG_PAGE_H
#define ATOM_UI_LV9_WIFI_CONFIG_PAGE_H

#include "lvgl.h"
#include "ConfigView/ConfigView.h"

class WiFiConfigPage {
public:
    static lv_obj_t *create();
    static lv_obj_t *del();
};

#endif // ATOM_UI_LV9_WIFI_CONFIG_PAGE_H