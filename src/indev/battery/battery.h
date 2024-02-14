#ifndef ATOM_UI_BATTERY_H
#define ATOM_UI_BATTERY_H

#include <Arduino.h>
#include <driver/adc.h>
#include "indev/io_map/io_map.h"
#include "common/log/log.h"

class Battery {
public:
    const uint16_t ORIGIN_MAX = 3000;   // ADC原始最大值
    const uint16_t sampling_during = 5;   // 采样时间（s）
    uint16_t sampling_cur = 0;
    uint16_t adc_origin;
    String perc_battery;

    void init();
    uint16_t get_origin();
    String get_perc();
};

#endif //ATOM_UI_BATTERY_H
