#include <TFT_eSPI.h>
#include "indev.h"
#include "common/log/log.h"
#include "ESP32Encoder.h"

/* 显示屏像素设置 */
static const uint16_t SCREEN_WIDTH  = 320;
static const uint16_t SCREEN_HEIGHT = 240;

/* 显示方向 */
static const uint8_t DISP_DIR = 1;

TFT_eSPI tft = TFT_eSPI(SCREEN_WIDTH, SCREEN_HEIGHT);

/* 显示缓存 */
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[SCREEN_WIDTH * 10 ];

/* UI操作组注册 */
lv_indev_t *indev;
lv_group_t *ui_group;

/* 旋转编码器 */
ESP32Encoder enc;

int enc_diff = 0;
int enc_diff_last = 0;

/* 显示刷新函数 */
void disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p ) {
    uint32_t width = (area->x2 - area->x1 + 1);
    uint32_t height = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, width, height);
    tft.pushColors((uint16_t *)&color_p->full, width * height, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

/* 编码器按键检测 */
lv_indev_state_t enc_read_push() {
    if (digitalRead(EC_BT) == ENC_IO_PUSHED)
        return LV_INDEV_STATE_PR;
    else
        return LV_INDEV_STATE_REL;
}

/* 编码器旋转检测 */
uint16_t enc_read_diff() {
    enc_diff = int(float(enc.getCount() / 2));
    return enc_diff - enc_diff_last;
}

static void lv_key_read(lv_indev_drv_t* indev_driver, lv_indev_data_t* data) {
    data -> enc_diff = enc_read_diff();
    data -> state = enc_read_push();

    enc_diff_last = enc_diff;
}

void lv_group_init() {
    ui_group = lv_group_create();
    lv_group_remove_all_objs(ui_group);

    lv_indev_set_group(lv_indev_drv_register(&indev_drv), ui_group);
}

void lv_encoder_drv_init() {
    pinMode(EC_BT, INPUT_PULLUP);

    enc.attachHalfQuad(EC_A, EC_B);
    enc.setFilter(800);
    enc.setCount(0);

    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = lv_key_read;
    indev = lv_indev_drv_register(&indev_drv);
}

void lv_disp_init() {
    digitalWrite(TFT_BL, LOW);

    tft.begin();          /* TFT init */
    tft.setRotation(DISP_DIR ); /* Landscape orientation, flipped */

    digitalWrite(TFT_BL, LOW);

    lv_disp_draw_buf_init(&draw_buf, buf, nullptr, SCREEN_WIDTH * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = SCREEN_WIDTH;
    disp_drv.ver_res = SCREEN_HEIGHT;
    disp_drv.flush_cb = disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );
}

void lv_port_drv_init() {
    Log::begin(115200);

    lv_disp_init();
    lv_encoder_drv_init();
    
    Battery::init();

    lv_group_init();

    bl_set_gradual(BL_ON, 2000);
}
