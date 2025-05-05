#include "Display.h"

uint32_t draw_buf[DRAW_BUF_SIZE / 4];
lv_disp_t *disp;

/**
 * @brief 显示屏初始化
 */
void Display::init() {
    disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, sizeof(draw_buf));

    TFT_BackLight.set_BL_delay_brightness(BL_DEFAULT, 800);
}
