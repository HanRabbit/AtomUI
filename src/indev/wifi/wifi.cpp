#include "wifi.h"
#include "common/log/log.h"

void wifi_init() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void wifi_set_time() {
    configTime(gmt_offset_sec, day_light_offset_sec, ntp_server);
}

bool get_wifi_status() {
    if (WiFiClass::status() == WL_CONNECTED) {
        if (!time_has_been_corrected) {
            wifi_set_time();
            time_has_been_corrected = true;
        }
        return true;
    } else {
        return false;
    }
}
