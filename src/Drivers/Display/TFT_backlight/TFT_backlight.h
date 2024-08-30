#ifndef TFT_BACKLIGHT_H
#define TFT_BACKLIGHT_H

#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>

#define BL_OFF 0

/* TFT显示屏背光控制类 */
class TFT_BackLight_ {
public:
    int32_t brightness = 0;

    /* 设置显示屏背光亮度 */
    void set_BL_brightness(int32_t brightness);

    void set_BL_delay_brightness(int32_t brightness, uint16_t delay);

    /* 获取显示屏背光亮度 */
    int32_t get_BL_brightness();
};

extern TFT_BackLight_ TFT_BackLight;

#endif //TFT_BACKLIGHT_H
