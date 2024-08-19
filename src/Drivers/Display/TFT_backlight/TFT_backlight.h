#ifndef TFT_BACKLIGHT_H
#define TFT_BACKLIGHT_H

#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>

#define BL_OFF 0

/* TFT显示屏背光控制类 */
class TFT_BackLight {
public:
    /* 设置显示屏背光亮度 */
    static void set_BL_brightness(int32_t brightness);

    /* 获取显示屏背光亮度 */
    static int32_t get_BL_brightness();
};

#endif //TFT_BACKLIGHT_H
