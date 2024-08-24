#include "Common.h"

void Common::init() {
    /* 定时器管理器初始化 */
    Timer_Manager.init();

    /* USB 调试初始化 */
    USB_log.init();

    JsonDocument json_;
    json_["wifi-name"] = "U-home";
    json_["wifi-password"] = "MyHome_16$5334783";

    File_Manager.cfg_write(json_, File_Manager.FILE_CONFIG_WIFI_PATH);

    JsonDocument json;
    json = File_Manager.cfg_read(File_Manager.FILE_CONFIG_WIFI_PATH);

    String json_str;
    serializeJsonPretty(json, json_str);
    LV_LOG_USER(json_str.c_str());

    LV_LOG_USER(File_Manager.f_read(File_Manager.FILE_LOG_PATH).c_str());
}
