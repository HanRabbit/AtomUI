#ifndef ATOM_UI_TFT_BACKLIGHT_H
#define ATOM_UI_TFT_BACKLIGHT_H

#include <Arduino.h>
#include <TFT_eSPI.h>

#include "common/log/log.h"
#include "ui/utils/ui_utils.h"

#define BL_ON 255
#define BL_OFF 0

void bl_set_brightness(uint16_t brightness);

uint16_t bl_get_brightness();

void bl_set_gradual(uint16_t target, uint16_t time);

#endif //ATOM_UI_TFT_BACKLIGHT_H
