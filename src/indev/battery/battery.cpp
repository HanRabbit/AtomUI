#include "battery.h"
#include "common/log/log.h"

void battery_init() {
    gpio_set_direction(GPIO_NUM_35, GPIO_MODE_INPUT);
    adc1_config_channel_atten(ADC1_CHANNEL_7, ADC_ATTEN_DB_11);
}

uint16_t get_battery() {
    uint16_t adc_origin = adc1_get_raw(ADC1_CHANNEL_7);
    return adc_origin;
}