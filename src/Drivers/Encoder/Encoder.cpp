#include "Encoder.h"
#include "Drivers/IO_Map/IO_map.h"
#include "UI/Utils/UIGroup/UIGroup.h"

ESP32Encoder enc;
Encoder encoder;

lv_indev_state_t Encoder::read_enc_push() {
    if (digitalRead(ENC_BT) == ENC_IO_PUSHED) {
        return LV_INDEV_STATE_PR;
    } else {
        return LV_INDEV_STATE_REL;
    }
}

/**
 * @brief 编码器旋转检测
 * @return 编码器值
 */
int16_t Encoder::read_enc_val() {
    enc_diff = static_cast<uint16_t> (static_cast<float> (enc.getCount() / 2));
    return enc_diff - enc_diff_last;
}

void encoder_read(lv_indev_t *indev, lv_indev_data_t *indev_data) {
    indev_data->enc_diff = encoder.read_enc_val();
    indev_data->state = encoder.read_enc_push();

    encoder.enc_diff_last = encoder.enc_diff;
}

void Encoder::encoder_drv_init() {
    pinMode(ENC_BT, INPUT_PULLUP);

    enc.attachHalfQuad(ENC_A, ENC_B);
    enc.setFilter(800);
    enc.setCount(0);

    indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_ENCODER);
    lv_indev_set_read_cb(indev, encoder_read);

    group = lv_group_create();
    lv_group_remove_all_objs(group);
    lv_indev_set_group(indev, group);
}

