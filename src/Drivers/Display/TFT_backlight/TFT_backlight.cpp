#include "TFT_backlight.h"

lv_anim_t BL_anim;

/* 背光动画过渡时间 ( ms ) */
uint16_t duration = 800;

/**
 * @brief 显示屏背光回调函数
 */
void BL_anim_callback(void *obj, int32_t brightness) {
    analogWrite(TFT_BL, brightness);
}

/**
 * @brief 设置显示屏亮度值
 * @param brightness 显示屏亮度值 (0 ~ 255)
 */
void TFT_BackLight::set_BL_brightness(int32_t brightness) {
    lv_anim_init(&BL_anim);
    lv_anim_set_exec_cb(&BL_anim, BL_anim_callback);
    lv_anim_set_values(&BL_anim, get_BL_brightness(), brightness);
    lv_anim_set_time(&BL_anim, duration);
    lv_anim_start(&BL_anim);
}


int32_t TFT_BackLight::get_BL_brightness() {
    return analogRead(TFT_BL);
}

