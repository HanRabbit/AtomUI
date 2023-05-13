#ifndef ATOM_UI_SELF_CHECK_H
#define ATOM_UI_SELF_CHECK_H

#include <Arduino.h>

#include "indev/indev.h"
#include "indev/sd/sd.h"

#define SYS_SELF_CHECK_OK 0

uint8_t sys_indev_check();

#endif //ATOM_UI_SELF_CHECK_H
