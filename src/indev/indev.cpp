#include <TFT_eSPI.h>
#include "indev.h"

/* Change to screen resolution */
static const uint16_t SCREEN_WIDTH  = 320;
static const uint16_t SCREEN_HEIGHT = 240;

TFT_eSPI tft = TFT_eSPI(SCREEN_WIDTH, SCREEN_HEIGHT); /* TFT instance */

static const uint8_t DISP_DIR = 1;

static const uint8_t PIN_UP = 36;
static const uint8_t PIN_DOWN = 37;
static const uint8_t PIN_ENTER = 35;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[SCREEN_WIDTH * 10 ];

lv_indev_drv_t indev_drv;

lv_group_t *ui_group;

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p ) {
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}

uint8_t Key_Scan() {
    if (digitalRead(PIN_ENTER) == LOW) {
        return 1;
    }
    if (digitalRead(PIN_UP) == LOW) {
        return 2;
    }
    else if (digitalRead(PIN_DOWN) == LOW) {
        return 3;
    }
    return 0;
}

static void lv_key_read(lv_indev_drv_t* indev_driver, lv_indev_data_t* data) {
    static uint32_t last_key = 0;
    uint8_t act_enc = Key_Scan();

    if (act_enc != 0) {
        switch (act_enc) {
            case 1:
                act_enc = LV_KEY_ENTER;
                data->state = LV_INDEV_STATE_PRESSED;
                break;
            case 2:
                act_enc = LV_KEY_RIGHT;
                data->state = LV_INDEV_STATE_PRESSED;
                // data->enc_diff++;
                break;
            case 3:
                act_enc = LV_KEY_LEFT;
                data->state = LV_INDEV_STATE_PRESSED;
                // data->enc_diff--;
                break;
        }
        last_key = (uint32_t)act_enc;
    }
    data->key = last_key;
}

void lv_group_init() {
    ui_group = lv_group_create();
    lv_group_set_default(ui_group);
    lv_group_remove_all_objs(ui_group);

    lv_indev_set_group(lv_indev_drv_register(&indev_drv), ui_group);
}

void lv_set_group(lv_group_t *tar_group) {
    ui_group = tar_group;
}

void lv_encoder_drv_init() {
    pinMode(PIN_ENTER, INPUT_PULLUP);
    pinMode(PIN_UP, INPUT_PULLUP);
    pinMode(PIN_DOWN, INPUT_PULLUP);

    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = lv_key_read;
    lv_indev_drv_register(&indev_drv);
}

void lv_disp_init() {
    tft.begin();          /* TFT init */
    tft.setRotation(DISP_DIR ); /* Landscape orientation, flipped */

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, SCREEN_WIDTH * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = SCREEN_WIDTH;
    disp_drv.ver_res = SCREEN_HEIGHT;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );
}

void lv_port_drv_init() {
    lv_disp_init();
    lv_encoder_drv_init();
    lv_group_init();

    bl_set_gradual(255, 400);
}
