#ifndef LOG_H
#define LOG_H

#include <Arduino.h>
#include <lvgl.h>

#define BAUD_RATE 115200

class USB_Log {
public:
  /* 初始化 USB 调试 */
  void init();
};

#endif //LOG_H
