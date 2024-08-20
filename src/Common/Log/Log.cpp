#include "Log.h"

void log_print(lv_log_level_t level, const char *buf) {
    LV_UNUSED(level);
    USBSerial.println(buf);
    USBSerial.flush();
}

void USB_Log::init() {
    lv_log_register_print_cb(log_print);
    USBSerial.begin(BAUD_RATE);
}
