#ifndef ATOM_UI_LOG_H
#define ATOM_UI_LOG_H

#include <Arduino.h>

#define LOG_IS_USE_SERIAL 1

#if LOG_IS_USE_SERIAL
#define Log USBSerial
#endif

#endif //ATOM_UI_LOG_H
