#ifndef ATOM_UI_HOME_VIEW_H
#define ATOM_UI_HOME_VIEW_H

#include <Arduino.h>
#include <lvgl.h>
#include "ui/res/rp/rp.h"

#define HOME_SIDE_BAR_OUT_TIME 1
#define HOME_SIDE_BAR_BG_COLOR 0x0
#define HOME_SIDE_BAR_BUTTON_COLUMN 26

void home_ui_init(lv_obj_t *scr);

#endif //ATOM_UI_HOME_VIEW_H
