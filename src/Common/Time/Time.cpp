#include "Time.h"

Time_ Time;

/* 联网将校准时间 */

/**
 * @brief Time 类初始化
 */
void Time_::init() {
    /* tm 结构体定义 设置初始时间为 2023年5月2日 12:44:00 */
    time_.tm_year = 2023 - 1900;
    time_.tm_mon = 5 - 1;
    time_.tm_mday = 2;
    time_.tm_hour = 12;
    time_.tm_min = 44;
    time_.tm_sec = 0;

    time_t time_since_epoch = mktime(&time_);
    timeval now = {.tv_sec = time_since_epoch};

    /* 设置系统时间 */
    settimeofday(&now, nullptr);
}

/**
 *
 * @param has_sec 输出秒数
 * @return 时间字符串
 */
String Time_::get_time_str(bool has_sec) {
    String time_str;

    if (getLocalTime(&time_, GET_TIME_OUT)) {
        /* 时间字符串首位补0 */
        time_str = (time_.tm_hour < 10 ? "0" : "") + String(time_.tm_hour) + ":" + (time_.tm_min < 10 ? "0" : "") + String(time_.tm_min);
        if (has_sec) {
            time_str += ":" + String(time_.tm_sec);
        }
    } else {
        /* 获取时间超时返回空 */
        time_str = "";
    }

    return time_str;
}

/**
 *
 * @param info 时间类型
 * @return 指定时间类型值
 */
uint8_t Time_::get_time_info(time_info info){
    getLocalTime(&time_, GET_TIME_OUT);
    switch (info) {
        case t_year:
            return time_.tm_year;
        case t_month:
            return time_.tm_mon;
        case t_day:
            return time_.tm_mday;
        case t_hour:
            return time_.tm_hour;
        case t_min:
            return time_.tm_min;
        case t_sec:
            return time_.tm_sec;
        default:
            return -1;
    }
}

