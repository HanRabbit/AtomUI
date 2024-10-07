#include "TFT_backlight.h"

lv_anim_t BL_anim;

/* 背光动画过渡时间 ( ms ) */
const uint16_t duration = 200;

TFT_BackLight_ TFT_BackLight;

/**
 * @brief 显示屏背光回调函数
 */
void BL_anim_callback(void *obj, int32_t brightness_) {
    TFT_BackLight.brightness = brightness_;
    analogWrite(TFT_BL, brightness_);
}

int32_t TFT_BackLight_::get_BL_brightness() {
    return brightness;
}

/**
 * @brief 设置显示屏亮度值
 * @param brightness 显示屏亮度值 (0 ~ 255)
 */
void TFT_BackLight_::set_BL_brightness(int32_t brightness) {
    lv_anim_init(&BL_anim);
    lv_anim_set_var(&BL_anim, nullptr);
    lv_anim_set_exec_cb(&BL_anim, BL_anim_callback);
    lv_anim_set_values(&BL_anim, get_BL_brightness(), brightness);
    lv_anim_set_duration(&BL_anim, duration);
    lv_anim_start(&BL_anim);
}

/**
 * @brief 延迟设置显示屏亮度值
 * @param brightness 显示屏亮度值 (0 ~ 255)
 * @param delay 延迟时间 (ms)
 */
void TFT_BackLight_::set_BL_delay_brightness(int32_t brightness, uint16_t delay) {
    lv_anim_init(&BL_anim);
    lv_anim_set_var(&BL_anim, nullptr);
    lv_anim_set_exec_cb(&BL_anim, BL_anim_callback);
    lv_anim_set_values(&BL_anim, get_BL_brightness(), brightness);
    lv_anim_set_duration(&BL_anim, duration);
    lv_anim_set_delay(&BL_anim, delay);
    lv_anim_start(&BL_anim);
}
