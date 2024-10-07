#ifndef ATOM_UI_LV9_STATUS_BAR_H
#define ATOM_UI_LV9_STATUS_BAR_H

#include <lvgl.h>
#include "UI/Utils/PageManager/PageManager.h"
#include "UI/Res/ResourcePool/ResourcePool.h"

#define STATUS_BAR_DURATION_UPDATE 2000

class Status_Bar {
public:
    lv_obj_t *back_button, *back_icon, *wifi_mode, *wifi_icon, *info_label, *battery_icon, *battery_perc_label, *battery_inside;

    void create(lv_obj_t *root);
};

extern Status_Bar StatusBar;

#endif // ATOM_UI_LV9_STATUS_BAR_H
