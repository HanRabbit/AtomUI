#include "Common.h"

void Common::init() {
    /* 定时器管理器初始化 */
    TimerManager.init();

    /* USB 调试初始化 */
    USB_log.init();

    /* WiFi 初始化 */
    WiFi_Op.init();
}
