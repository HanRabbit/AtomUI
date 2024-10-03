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
  /* 系统时间结构体 */
  struct tm time_;

  /* 时间类联网校准 */
  void init();

  /* 获取当前时间字符串（状态栏及桌面） */
  String get_time_str(bool has_sec);

  /* 获取指定时间对象 */
  uint8_t get_time_info(time_info info);
};

extern Time_ Time;

#endif //TIME_H
