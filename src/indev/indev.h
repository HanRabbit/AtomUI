#ifndef ATOM_UI_INDEV_H
#define ATOM_UI_INDEV_H


#include <lvgl.h>
#include "tft_backlight/tft_backlight.h"
#include "battery/battery.h"

lv_group_t *ui_group;

const uint8_t EC_BT = 2;
const uint8_t EC_A = 18;
const uint8_t EC_B = 3;

void lv_port_drv_init();

void lv_set_group();

#endif
