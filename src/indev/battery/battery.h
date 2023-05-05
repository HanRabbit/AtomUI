#ifndef ATOM_UI_BATTERY_H
#define ATOM_UI_BATTERY_H

#include <Arduino.h>
#include <driver/adc.h>

#define BAT_PIN 35


void battery_init();
uint16_t get_battery();

#endif //ATOM_UI_BATTERY_H
