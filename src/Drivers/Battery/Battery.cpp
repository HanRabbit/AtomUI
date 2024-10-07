#include "Battery.h"
#include "Drivers/IO_Map/IO_map.h"
#include "Common/MessageManager/Account.h"
#include "Common/TimerManager/TimerManager.h"

Battery battery;

/**
 * @brief 电池电量检测初始化
 */
void Battery::init() {
    gpio_set_direction((gpio_num_t) BATTERY_PIN, GPIO_MODE_INPUT);
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_12);

    TimerManager.t_register([] (lv_timer_t *timer) {
        publisher.publish(MSG_ID_BATTERY_PERCENT, battery.get_percent());
    }, MSG_BATTERY_UPDATE_DURATION, MSG_ID_BATTERY_PERCENT, nullptr, true);
}

/**
 * @brief 获取电池电压 ADC 原始值
 * @return ADC 原始值
 */
uint16_t Battery::get_origin() {
    adc_origin = adc1_get_raw(ADC1_CHANNEL_4);
    return adc_origin;
}

String Battery::get_percent() {
    String percent = String((float) ((float)get_origin() / (float)200));

    return percent;
}
