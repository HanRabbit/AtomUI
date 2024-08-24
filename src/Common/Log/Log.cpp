#include "Log.h"
#include "Common/FileManager/FileManager.h"

USB_Log USB_log;

void log_print(lv_log_level_t level, const char *buf) {
    LV_UNUSED(level);
    
    if (USB_log.LOG_USE_SERIAL) {
        /* 使用串口输出日志 */
        USBSerial.println(buf);
        USBSerial.flush();
    }

    if (USB_log.LOG_USE_FS) {
        /* 使用 FS 输出日志 */
        File_Manager.log(buf);
    }
}

void USB_Log::out(const char *buf) {
    if (LOG_USE_USER_SERIAL) {
        USBSerial.println(buf);
    }
}

void USB_Log::init() {
    /* 注册日志输出回调函数 */
    lv_log_register_print_cb(log_print);

    /* USB 串口初始化 */
    USBSerial.begin(BAUD_RATE);
}
