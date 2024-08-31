#include "WiFi.h"

WiFi_OP WiFi_Op;

/**
 * @brief WiFi 初始化
 */
void WiFi_OP::init() {
    /* 获取 Wi-Fi 配置文件 */
    JsonDocument wifi_config_json = FileManager.cfg_read(FILE_CONFIG_WIFI_PATH);
    SSID = wifi_config_json["wifi-name"];
    PASSWORD = wifi_config_json["wifi-password"];

    WiFi.begin(SSID, PASSWORD);
}


bool WiFi_OP::is_connected() {
    if (WiFi.isConnected())
        return true;
    else
        return false;
}