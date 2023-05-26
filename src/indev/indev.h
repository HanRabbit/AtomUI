#ifndef ATOM_UI_INDEV_H
#define ATOM_UI_INDEV_H


#include <lvgl.h>
#include "tft_backlight/tft_backlight.h"
#include "battery/battery.h"
#include "io_map/io_map.h"

static lv_indev_drv_t indev_drv;

void lv_port_drv_init();

// void lv_set_group(lv_group_t *group);

#endif
