#ifndef ATOM_UI_LV9_WIFI_H
#define ATOM_UI_LV9_WIFI_H

#include <lvgl.h>
#include <ArduinoJson.h>
#include <WiFi.h>

class WiFi_OP {
private:
    const uint16_t WIFI_STATUS_UPDATE_DURATION = 1000;

public:
    const char *SSID, *PASSWORD;

    /* WiFi 初始化 */
    void init();

    /* Wi-Fi 状态更新 */
    const char *status_update();

    void wifi_write_config(const char *ssid, const char *password);
};

extern WiFi_OP WiFi_Op;

#endif // ATOM_UI_LV9_WIFI_H
