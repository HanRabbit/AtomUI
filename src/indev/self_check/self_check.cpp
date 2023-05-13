#include "self_check.h"

uint8_t sys_indev_check() {
    if (!sd_card_init()) {
        return 4;
    } else {
        return 0;
    }
}