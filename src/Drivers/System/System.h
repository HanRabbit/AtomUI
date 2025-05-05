#ifndef ATOM_UI_LV9_SYSTEM_H
#define ATOM_UI_LV9_SYSTEM_H

#include <Arduino.h>

/* 系统状态 */
enum system_status {
    SYSTEM_STATUS_NORMAL = 0,
    SYSTEM_STATUS_REBOOT,
    SYSTEM_STATUS_SHUTDOWN,
    SYSTEM_STATUS_SLEEP,
    SYSTEM_STATUS_ERROR
};

class AtomSystem{
private:
    float start_time_stamp;  /* 系统启动时的时间戳 */
    float start_duration;    /* 系统开机时间 */
    system_status status;       /* 系统状态 */
    uint8_t applications_num;   /* 系统应用程序数量 */

public:
    void launch_begin();
    void launch_end();
};

extern AtomSystem atom_system;

#endif // ATOM_UI_LV9_SYSTEM_H
