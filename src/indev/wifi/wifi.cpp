#include "wifi.h"

extern lv_obj_t *ui_wifiMode;
extern lv_obj_t *ui_wifiIcon;

LV_IMG_DECLARE(ui_img_wifi_png);   // assets\WIFI.png
LV_IMG_DECLARE(ui_img_wifi_closed_png);

String WiFi_MODE;

void wifi_init() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void wifi_status_update(lv_timer_t *timer) {
    if (WiFiClass::status() == WL_CONNECTED) {
        lv_img_set_src(ui_wifiIcon, &ui_img_wifi_png);
        switch (WiFiClass::getMode()) {
            case WIFI_MODE_NULL:
                WiFi_MODE = "NULL";
                break;
            case WIFI_MODE_STA:
                WiFi_MODE = "STA";
                break;
            case WIFI_MODE_AP:
                WiFi_MODE = "AP";
                break;
            case WIFI_MODE_APSTA:
                WiFi_MODE = "APSTA";
                break;
            case WIFI_MODE_MAX:
                WiFi_MODE = "MAX";
                break;
        }
    } else {
        lv_img_set_src(ui_wifiIcon, &ui_img_wifi_closed_png);
        WiFi_MODE = "";
    }
    lv_label_set_text(ui_wifiMode, WiFi_MODE.c_str());
}
