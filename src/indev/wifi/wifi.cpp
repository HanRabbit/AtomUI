#include "wifi.h"
#include "common/log/log.h"

extern lv_obj_t *ui_wifi_mode;
extern lv_obj_t *ui_wifi_icon;
extern lv_img_dsc_t ui_img_wifi_closed_png;
extern lv_img_dsc_t ui_img_wifi_png;

void wifi_init() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void wifi_set_time() {
    configTime(gmt_offset_sec, day_light_offset_sec, ntp_server);
}

void wifi_update_icon(wifi_icon_t wifi_icon) {
    lv_img_dsc_t *wifi_icon_png;
    switch (wifi_icon) {
        case WIFI_CONNECTED:
            wifi_icon_png = &ui_img_wifi_png;
            break;
        case WIFI_CLOSED:
            wifi_icon_png = &ui_img_wifi_closed_png;
            break;
        default:
            Log::error("WIFI", "Wifi icon is not illegal");
    }
    lv_img_set_src(ui_wifi_icon, wifi_icon_png);
}

void wifi_update_mode(wifi_mode_t mode) {
    switch (mode) {
        case WIFI_MODE_NULL:
            WiFi_MODE = "";
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
    lv_label_set_text(ui_wifi_mode, WiFi_MODE.c_str());
}

void wifi_status_update(lv_timer_t *timer) {
    if (WiFiClass::status() == WL_CONNECTED) {
        if (!time_has_been_corrected) {
            wifi_set_time();
            time_has_been_corrected = true;
        }

        wifi_update_mode(WiFiClass::getMode());
        wifi_update_icon(WIFI_CONNECTED);
    } else {
        wifi_update_mode(WIFI_MODE_NULL);
        wifi_update_icon(WIFI_CLOSED);
    }
}
