#include "ota_update.h"

void put_update_start() {
    LOG_.println("CALLBACK:  HTTP update process started");
}

void put_update_progress(int cur, int total) {
    LOG_.printf("CALLBACK:  HTTP update process at %d of %d bytes...\n", cur, total);
    lv_task_handler();
}

/**
 * @brief 通过OTA远程升级函数，需要在联网后调用
 */
t_httpUpdate_return OTA_update() {
    WiFiClient OTAClient;
    httpUpdate.rebootOnUpdate(false);
//    httpUpdate.onStart(put_update_start);
//    httpUpdate.onProgress(put_update_progress);
    t_httpUpdate_return hur = httpUpdate.update(OTAClient, OTA_UPDATE_URL);
    return hur;
}