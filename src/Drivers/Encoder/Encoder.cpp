//#include "Encoder.h"
//#include "Drivers/IO_Map/IO_map.h"
//
//ESP32Encoder enc;
//Encoder encoder;
//
//lv_indev_state_t Encoder::read_enc_push() {
//    if (digitalRead(ENC_BT) == ENC_IO_PUSHED) {
//        return LV_INDEV_STATE_PR;
//    } else {
//        return LV_INDEV_STATE_REL;
//    }
//}
//
///**
// * @brief 编码器旋转检测
// * @return 编码器值
// */
//int16_t Encoder::read_enc_val() {
//    enc_diff = int(float(enc.getCount() / 2));
//    return enc_diff - enc_diff_last;
//}
//
///* 编码器读取回调函数 */
//void *Encoder::encoder_read(lv_indev_t *indev, lv_indev_data_t *indev_data) {
//    indev_data -> enc_diff = read_enc_val();
//    indev_data -> state = read_enc_push();
//
//    enc_diff_last = enc_diff;
//}
//
//void Encoder::encoder_drv_init() {
//    lv_indev_set_type(indev, LV_INDEV_TYPE_ENCODER);
////    lv_indev_set_read_cb(indev, encoder_read);
//
//    group = lv_group_create();
//    lv_group_remove_all_objs(group);
//
//    lv_indev_set_group(indev, group);
//}
//
