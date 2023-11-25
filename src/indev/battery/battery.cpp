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
uint16_t Battery::get() {
    uint16_t adc_origin = adc1_get_raw(ADC1_CHANNEL_4);
    return adc_origin;
}