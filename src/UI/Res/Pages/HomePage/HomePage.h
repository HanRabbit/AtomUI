#ifndef ATOM_UI_LV9_HOME_PAGE_H
#define ATOM_UI_LV9_HOME_PAGE_H

#include <Arduino.h>
#include <lvgl.h>

#include "Common/Time/Time.h"
#include "Common/WiFi/WiFi.h"

/* 主页面刷新时间 ( ms ) */
#define HOME_PAGE_UPDATE_DURATION 2000

struct HomePage {
    static lv_obj_t *create();
    static lv_obj_t *del();
};

#endif // ATOM_UI_LV9_HOME_PAGE_H
