#include "time.h"

String Time::get_time_str(bool show_sec) {
    if (getLocalTime(&time_, 50)) {
        time_str = (time_.tm_hour < 10 ? "0" : "") + String(time_.tm_hour) + ":" + (time_.tm_min < 10 ? "0" : "") + String(time_.tm_min);
//        String time_year_str = String(time_.tm_year + 1900) + "-" + String(time_.tm_mon + 1) + "-" + String(time_.tm_mday);
        if (show_sec) {
            time_str += ":" + String(time_.tm_sec);
        }
    } else {
        time_str = "";
    }

    return time_str;
}

uint16_t Time::get_sec() {
    getLocalTime(&time_, 200);
    return time_.tm_sec;
}

uint16_t Time::get_min() {
    getLocalTime(&time_, 200);
    return time_.tm_min;
}

uint16_t Time::get_hour() {
    getLocalTime(&time_, 200);
    return time_.tm_hour;
}
