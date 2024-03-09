#include "battery.h"

void Battery::init() {
    gpio_set_direction((gpio_num_t) BATTERY_PIN, GPIO_MODE_INPUT);
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);
    return;
}

/**
 * @brief 获取电池电量
 * @return adc_origin: 原始ADC数据
 */
uint16_t Battery::get_origin() {
    if (sampling_cur >= sampling_during || sampling_cur == 0) {
        adc_origin = adc1_get_raw(ADC1_CHANNEL_4);
        sampling_cur = 0;
    }

    sampling_cur ++;
    return adc_origin;
}

/**
 * @brief 获取电池电量百分比
 * @return 电池电量百分比
 */
String Battery::get_perc() {
    perc_battery = String((ORIGIN_MAX - get_origin()) / ORIGIN_MAX) + "%";
    return "";
}