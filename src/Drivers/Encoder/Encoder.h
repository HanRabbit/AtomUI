#ifndef ATOM_UI_LV9_ENCODER_H
#define ATOM_UI_LV9_ENCODER_H

#include <Arduino.h>
#include <lvgl.h>
#include <ESP32Encoder.h>

#define ENC_IO_PUSHED 0

/* Encoder 编码器类 */
class Encoder {
public:
    /* 编码器参数 */
    uint16_t enc_diff = 0, enc_diff_last = 0;

    static lv_indev_state_t read_enc_push();
    int16_t read_enc_val();

    /* LVGL 操作注册 */
    lv_indev_t *indev;

    void encoder_drv_init();
};

extern Encoder encoder;

#endif // ATOM_UI_LV9_ENCODER_H
