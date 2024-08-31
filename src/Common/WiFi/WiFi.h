#ifndef ATOM_UI_LV9_WIFI_H
#define ATOM_UI_LV9_WIFI_H

#include <lvgl.h>
#include <ArduinoJson.h>
#include <WiFi.h>

#include "Common/FileManager/FileManager.h"


class WiFi_OP {
public:
    const char *SSID, *PASSWORD;

    /* WiFi 初始化 */
    void init();

    /* Wi-Fi 状态更新 */
    bool is_connected();
};

extern WiFi_OP WiFi_Op;

#endif // ATOM_UI_LV9_WIFI_H
