#include "Common.h"

USB_Log usb_log;
TimerManager timer_manager;

void Common::init() {
    /* USB 调试初始化 */
    usb_log.init();

    /* 定时器管理器初始化 */
    timer_manager.init();
}
