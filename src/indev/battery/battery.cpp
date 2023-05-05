#include "battery.h"
#include "common/log/log.h"

void battery_init() {
    gpio_set_direction(GPIO_NUM_35, GPIO_MODE_INPUT);

    adc1_config_channel_atten(ADC1_CHANNEL_7, ADC_ATTEN_DB_11);
    // adc1_config_width(ADC_WIDTH_12Bit);
    // adc1_config_channel_atten(ADC1_CHANNEL_MAX, ADC_ATTEN_DB_11);
}

uint16_t get_battery() {
    uint16_t adc_origin = adc1_get_raw(ADC1_CHANNEL_7);

    // float voltage = adc_origin / 4095.0 * 3.3;
    Log.println(adc_origin);
    return adc_origin;
}