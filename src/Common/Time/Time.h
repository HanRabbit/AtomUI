#ifndef TIME_H
#define TIME_H

#include <Arduino.h>

/* 校准超时时间 (ms) */
#define GET_TIME_OUT 50

/* 时间校准常量 */
#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 28800
#define DAYLIGHT_OFFSET_SEC 0

enum time_info {t_year, t_month, t_day, t_hour, t_min, t_sec};

class Time_ {
public:
    /* tm 结构体定义 设置初始时间为 2023年5月2日 12:44:00 */
    struct tm time_ = {0, 44, 12, 2, 5 - 1, 2023 - 1900, 0, 0, 0};

    /* 时间类初始化 */
    void init();

    /* 获取当前时间字符串（状态栏及桌面） */
    String get_time_str(bool has_sec);

    /* 获取当前时间秒数 */
    String get_time_str_sec();

    /* 获取指定时间对象 */
    uint8_t get_time_info(time_info info);

    /* 判断是否时间已校准 */
    bool time_adjusted() const;

    /* 校准时间 */
    void time_adjust();
};

extern Time_ Time;

#endif //TIME_H
