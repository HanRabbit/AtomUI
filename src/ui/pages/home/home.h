#ifndef ATOM_UI_HOME_H
#define ATOM_UI_HOME_H

#include <lvgl.h>
#include <Arduino.h>
#include "ui/utils/ui_utils.h"
#include "home_events.h"

//static lv_obj_t *ui_Panel1;
//static lv_obj_t *ui_Image1;
//static lv_obj_t *ui_Label4;
//static lv_obj_t *ui_Image2;
//static lv_obj_t *ui_Label5;
//static lv_obj_t *ui_Image3;
//static lv_obj_t *ui_Label6;
//static lv_obj_t *ui_Image4;
//static lv_obj_t *ui_Label7;

class HomePage {
public:
    static lv_obj_t *page_delete();
    static lv_obj_t *page_create();
};

#endif //ATOM_UI_HOME_H
