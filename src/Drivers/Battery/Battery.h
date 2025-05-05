#ifndef ATOM_UI_LV9_BATTERY_H
#define ATOM_UI_LV9_BATTERY_H

#include <Arduino.h>
#include <driver/adc.h>

class Battery {
private:
    const uint16_t ORIGIN_MAX = 200;       /* ADC 原始最大值 */
    uint16_t adc_origin {};

public:
    void init();
    uint16_t get_origin();
    String get_percent();
};

extern Battery battery;

#endif // ATOM_UI_LV9_BATTERY_H
