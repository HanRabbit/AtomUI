#ifndef DISPLAY_H
#define DISPLAY_H

#include <Drivers/Display/TFT_backlight/TFT_backlight.h>

/* 显示屏尺寸 */
#define TFT_HOR_RES   320
#define TFT_VER_RES   240

/* 显示缓冲区大小 */
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))

/* 背光默认亮度 */
#define BL_DEFAULT 255

class Display {
public:
  /* 显示屏初始化 */
  void init();
};

#endif //DISPLAY_H
