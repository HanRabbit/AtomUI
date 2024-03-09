#ifndef ATOM_UI_TIME_H
#define ATOM_UI_TIME_H

#include <Arduino.h>

/* 同步时间公共 time_ */
static struct tm time_;
static String time_str;

/* 时间获取超时时间 */
#define TIME_OUT 100

void time_init();

class Time {
public:
    static String get_time_str(bool show_sec);
    static uint16_t get_min();
    static uint16_t get_hour();
    static uint16_t get_sec();
};

#endif //ATOM_UI_TIME_H
