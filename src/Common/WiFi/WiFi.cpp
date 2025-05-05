#include "WiFi.h"
#include "Common/FileManager/FileManager.h"
#include "Common/MessageManager/Account.h"
#include "Common/TimerManager/TimerManager.h"
#include "Common/Time/Time.h"

WiFi_OP WiFi_Op;

/**
 * @brief WiFi 初始化
 */
void WiFi_OP::init() {
    /* 调试专用 */
    // wifi_write_config("iPhone4", "05133315");

    /* 获取 Wi-Fi 配置文件 */
    JsonDocument wifi_config_json = FileManager.cfg_read(FILE_CONFIG_WIFI_PATH);
    SSID = wifi_config_json["wifi-name"];
    PASSWORD = wifi_config_json["wifi-password"];
    
    LV_LOG_USER("WIFI Name: %s", SSID);
    LV_LOG_USER("WIFI PASSWORD: %s", PASSWORD);

    /* Wi-Fi 开始连接 */
    WiFi.begin(SSID, PASSWORD);

    /* 注册 Wi-Fi 状态刷新定时器 */
    TimerManager.t_register([] (lv_timer_t *timer) {
        publisher.publish(MSG_ID_WIFI_STATUS, WiFi_Op.status_update());
    }, WIFI_STATUS_UPDATE_DURATION, "WIFI_STATUS_UPDATE", nullptr, true);
}

const char *WiFi_OP::status_update() {
    if (WiFi.isConnected()) {
        if (!Time.time_adjusted()) {
            /* 第一次联网后校准时间 */
            Time.time_adjust();
        }
        return MSG_CONTENT_WIFI_CONNECTED;
    } else {
        return MSG_CONTENT_WIFI_DISCONNECTED;
    }
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
