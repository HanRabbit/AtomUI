//#ifndef ATOM_UI_LV9_ENCODER_H
//#define ATOM_UI_LV9_ENCODER_H
//
//#include <Arduino.h>
//#include <lvgl.h>
//#include <ESP32Encoder.h>
//
//#define ENC_IO_PUSHED 0
//
///* Encoder 编码器类 */
//class Encoder {
//private:
//    /* 编码器参数 */
//    int16_t enc_diff = 0, enc_diff_last = 0;
//
//    lv_indev_state_t read_enc_push();
//    int16_t read_enc_val();
//
//    void *encoder_read(lv_indev_t *indev, lv_indev_data_t *indev_data);
//
//public:
//    /* LVGL 操作注册 */
//    lv_indev_t *indev = lv_indev_create();
//    lv_group_t *group;
//
//    void encoder_drv_init();
//};
//
//#endif // ATOM_UI_LV9_ENCODER_H
