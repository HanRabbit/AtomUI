#ifndef ATOM_LOG_H
#define ATOM_LOG_H

#include <Arduino.h>
#include <lvgl.h>

#define BAUD_RATE 115200    /* 串口波特率 */

class USB_Log {
public:
    /* 是否输出日志文件到串口 */
    bool LOG_USE_SERIAL = true;

    /* 是否输出日志文件到 SD 卡 */
    bool LOG_USE_FS = true;

    /* 是否允许用户串口调试 */
    bool LOG_USE_USER_SERIAL = false;

    /* 初始化 USB 调试 */
    void init();

    /* 仅使用 USB 串口调试 */
    void out(const char *buf) const;
};

extern USB_Log USB_log;

#endif //ATOM_LOG_H
