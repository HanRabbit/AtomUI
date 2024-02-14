#include "time.h"

/**
 * @brief 获取时间字符串
 * @param show_sec 是否显示秒
 * @return 时间字符串
 */
String Time::get_time_str(bool show_sec) {
    if (getLocalTime(&time_, 50)) {
        time_str = (time_.tm_hour < 10 ? "0" : "") + String(time_.tm_hour) + ":" + (time_.tm_min < 10 ? "0" : "") + String(time_.tm_min);
        if (show_sec) {
            time_str += ":" + String(time_.tm_sec);
        }
    } else {
        time_str = "";
    }

    return time_str;
}

uint16_t Time::get_sec() {
    getLocalTime(&time_, TIME_OUT);
    return time_.tm_sec;
}

uint16_t Time::get_min() {
    getLocalTime(&time_, TIME_OUT);
    return time_.tm_min;
}

uint16_t Time::get_hour() {
    getLocalTime(&time_, TIME_OUT);
    return time_.tm_hour;
}
