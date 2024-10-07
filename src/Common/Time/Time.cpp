#include "Time.h"
#include "Common/MessageManager/Account.h"
#include "Common/TimerManager/TimerManager.h"

Time_ Time;

/* 联网将校准时间 */

/**
 * @brief 发布时间消息
 */
void publish_time_msg() {
    /* 注册定时器发送消息 */
    TimerManager.t_register([] (lv_timer_t *timer) {
        publisher.publish(MSG_ID_TIME_HM, Time.get_time_str(false).c_str());
    }, 1000, MSG_ID_TIME_HM, nullptr, false);

    TimerManager.t_register([] (lv_timer_t *timer) {
        publisher.publish(MSG_ID_TIME_SEC, Time.get_time_str_sec().c_str());
    }, 1000, MSG_ID_TIME_SEC, nullptr, false);
}

/**
 * @brief Time 类初始化
 */
void Time_::init() {
    time_t time_since_epoch = mktime(&time_);
    timeval now = {.tv_sec = time_since_epoch};

    /* 设置系统时间 */
    settimeofday(&now, nullptr);

    publish_time_msg();
}

/**
 * @brief 获取时间字符串
 * @param has_sec 输出秒数
 * @return 时间字符串
 */
String Time_::get_time_str(bool has_sec) {
    String time_str;

    if (getLocalTime(&time_, GET_TIME_OUT)) {
        /* 时间字符串首位补 0 */
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

/**
 * @brief 时间是否已经校准
 * @return true: 校准完成, false: 未完成
 */
bool Time_::time_adjusted() const {
    if (time_.tm_year == 2023 - 1900)
        return false;
    else
        return true;
}

/**
 * @brief 校准时间
 */
void Time_::time_adjust() {
    configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
}

String Time_::get_time_str_sec() {
    if (getLocalTime(&time_, GET_TIME_OUT)) {
        return String(time_.tm_sec);
    } else {
        /* 获取时间超时 */
        return "";
    }
}
