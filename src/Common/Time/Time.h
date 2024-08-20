#ifndef TIME_H
#define TIME_H

#include <Arduino.h>

/* 校准超时时间 (ms) */
#define GET_TIME_OUT 50

enum time_info {t_year, t_month, t_day, t_hour, t_min, t_sec};

class Time {
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

#endif //TIME_H
