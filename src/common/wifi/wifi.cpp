#include "wifi.h"
#include "common/log/log.h"

/**
 * @brief WiFi初始化
 */
void wifi_init() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

/**
 * @brief 联网校准时间
 */
void wifi_set_time() {
    configTime(gmt_offset_sec, day_light_offset_sec, ntp_server);
}

/**
 * @brief 获取WiFi连接状态
 * @return ture: 已连接, false: 未连接
 */
bool get_wifi_status() {
    if (WiFi.isConnected()) {
        if (!time_has_been_corrected) {
            wifi_set_time();
            time_has_been_corrected = true;
        }
        return true;
    } else {
        return false;
    }
}
