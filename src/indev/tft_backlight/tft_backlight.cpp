#include "tft_backlight.h"

lv_anim_t a;

/**
    * @brief 设置背光亮度
    * @param brightness: 亮度（0 ~ 255）
    */
void bl_set_brightness(uint16_t brightness) {
    analogWrite(TFT_BL, brightness);
}

/**
    * @brief 获取背光亮度
    * @return 背光亮度 （0 ~ 255）
    */
uint16_t bl_get_brightness() {
    return analogRead(TFT_BL);
}

/**
    * @brief 背光亮度渐变动画回调
    * @param obj: NULL
    * @param brightness: 亮度
*/
void bl_anim_callback(void *obj, int16_t brightness) {
    bl_set_brightness(brightness);
}

/**
     * @brief 设置背光渐变动画效果
     * @param target: 更改到目标值（0 ~ 255）
     * @param time: 动画时间（ms）
     */
void bl_set_gradual(uint16_t target, uint16_t time) {
    lv_obj_add_anim(nullptr, &a, (lv_anim_exec_xcb_t)bl_anim_callback, 0,
                    target, time,
                    nullptr, lv_anim_path_linear);
}