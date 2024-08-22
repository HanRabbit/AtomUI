#include "Drivers.h"

Display display;
SD_Card sd_card;

void Drivers::init() {
    /* 显示屏初始化 */
    display.init();

    sd_card.init();
}
