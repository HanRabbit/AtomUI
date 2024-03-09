#include "ota_update.h"

/**
 * @brief 通过OTA远程升级函数，需要在联网后调用
 */
t_httpUpdate_return OTA_update() {
    WiFiClient OTAClient;
    httpUpdate.rebootOnUpdate(false);
    t_httpUpdate_return hur = httpUpdate.updateSpiffs(OTAClient, OTA_UPDATE_URL);
    return hur;
}