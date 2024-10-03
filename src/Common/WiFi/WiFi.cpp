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

    LV_LOG_USER("WIFI Name: %s", SSID);
    LV_LOG_USER("WIFI PASSWORD: %s", PASSWORD);

    /* Wi-Fi 开始连接 */
    WiFi.begin(SSID, PASSWORD);
}


bool WiFi_OP::is_connected() {
    if (WiFi.isConnected())
        return true;
    else
        return false;
}

/**
 * @brief Wi-Fi 配置写入（ 调试用 ）
 */
void WiFi_OP::wifi_write_config(const char *ssid, const char *password) {
    JsonDocument wifi_config;
    wifi_config["wifi-name"] = ssid;
    wifi_config["wifi-password"] = password;

    FileManager.cfg_write(wifi_config, FILE_CONFIG_WIFI_PATH);
}