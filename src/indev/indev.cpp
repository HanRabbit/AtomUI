#include <TFT_eSPI.h>
#include "indev.h"
#include "ESP32Encoder.h"

/* Change to screen resolution */
static const uint16_t SCREEN_WIDTH  = 320;
static const uint16_t SCREEN_HEIGHT = 240;

TFT_eSPI tft = TFT_eSPI(SCREEN_WIDTH, SCREEN_HEIGHT); /* TFT instance */

static const uint8_t DISP_DIR = 1;

static const uint8_t EC_BT = 2;
static const uint8_t EC_A = 18;
static const uint8_t EC_B = 3;

ESP32Encoder enc;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[SCREEN_WIDTH * 10 ];

lv_indev_drv_t indev_drv;

uint16_t tft_bl_ = 0;

long enc_diff = 0, enc_diff_last = 0;
lv_indev_state_t enc_stat;

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

void Key_Scan() {
    static bool but_flag = true;
	
    if(digitalRead(EC_BT) == 0)	//编码器的按键
        enc_stat = LV_INDEV_STATE_PR;	//按下
    else
        enc_stat = LV_INDEV_STATE_REL;	//松开

    enc_diff = enc.getCount() / 2;

    // if(digitalRead(EC_A) == 0 && digitalRead(EC_B) == 0 && but_flag)	    //编码器左转
    // {
   	//  	enc_diff --;
    //     but_flag = false;
    // }
    // else if(digitalRead(EC_A) == 1 && digitalRead(EC_B) == 1 && but_flag)       //编码器右转
    // {
    // 	enc_diff ++;
    //     but_flag = false;
    // }
    // else if(digitalRead(EC_A) == 1 && digitalRead(EC_B) == 0)
    //     but_flag = true;

    // USBSerial.println(enc_diff);
    // USBSerial.println("EC_A=" + String(digitalRead(EC_A)));
    // USBSerial.println("EC_B=" + String(digitalRead(EC_B)));
}

static void lv_key_read(lv_indev_drv_t* indev_driver, lv_indev_data_t* data) {
    Key_Scan();

    if (enc_diff > enc_diff_last) {
        data->enc_diff = -1;
        data->state = enc_stat;
    } else if (enc_diff < enc_diff_last) {
        data->enc_diff = 1;
        data->state = enc_stat;
    } else {
        data->enc_diff = 0;
        data->state = enc_stat;
    }

    enc_diff_last = enc_diff;
    
    return;
}

void lv_set_groups() {
    ui_group = lv_group_create();
    lv_group_set_default(ui_group);
    lv_group_remove_all_objs(ui_group);

    /* add objects to your groups */


    lv_indev_set_group(lv_indev_drv_register(&indev_drv), ui_group);
}

void lv_encoder_drv_init() {
    pinMode(EC_BT, INPUT_PULLUP);
    // pinMode(EC_A, INPUT_PULLUP);
    // pinMode(EC_B, INPUT_PULLUP);
    enc.attachHalfQuad(EC_A, EC_B);
    enc.setCount(0);

    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = lv_key_read;
    lv_indev_drv_register(&indev_drv);
}

void lv_disp_init() {
    digitalWrite(TFT_BL, LOW);

    tft.begin();          /* TFT init */
    tft.setRotation(DISP_DIR ); /* Landscape orientation, flipped */

    digitalWrite(TFT_BL, LOW);

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
    Log.begin(115200);

    lv_disp_init();
    lv_encoder_drv_init();
    
    battery_init();

    lv_set_groups();

    bl_set_gradual(BL_ON, 200);
}
