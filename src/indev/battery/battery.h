#ifndef ATOM_UI_BATTERY_H
#define ATOM_UI_BATTERY_H

#include <Arduino.h>
#include <driver/adc.h>
#include "indev/io_map/io_map.h"
#include "common/log/log.h"

void battery_init();
uint16_t get_battery();

#endif //ATOM_UI_BATTERY_H
