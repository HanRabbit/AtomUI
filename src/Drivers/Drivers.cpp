#include "Drivers.h"

Display display;
USB_Log usb_log;

void Drivers::init() {
    /* 显示屏初始化 */
    display.init();

    /* USB 调试初始化 */
    usb_log.init();
}
