#include "Drivers.h"

#include "Drivers/Display/Display.h"
#include "Common/Log/Log.h"
#include "Drivers/SD_Card/SD_Card.h"
#include "Drivers/Battery/Battery.h"
#include "Drivers/System/System.h"

Display display;
SD_Card sd_card;

void Drivers::init() {
    /* 系统开始启动，设置系统启动时间戳 */
    atom_system.launch_begin();

    /* 驱动初始化 */
    display.init();
    sd_card.init();
    battery.init();
}
