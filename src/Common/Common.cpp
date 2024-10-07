#include "Common.h"

void Common::init() {
    /* USB 调试初始化 */
    USB_log.init();

    /* WiFi 初始化 */
    WiFi_Op.init();

    Time.init();
}
