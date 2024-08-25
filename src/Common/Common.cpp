#include "Common.h"

void Common::init() {
    /* 定时器管理器初始化 */
    Timer_Manager.init();

    /* USB 调试初始化 */
    USB_log.init();
}
