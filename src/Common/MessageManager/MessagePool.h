#ifndef ATOM_UI_LV9_MESSAGE_POOL_H
#define ATOM_UI_LV9_MESSAGE_POOL_H

#include <Arduino.h>
#include <unordered_map>
#include <vector>

/* WiFi 消息状态 */
#define MSG_ID_WIFI_STATUS              "WIFI/STATUS"
#define MSG_CONTENT_WIFI_CONNECTED      "CONNECTED"
#define MSG_CONTENT_WIFI_DISCONNECTED   "DISCONNECTED"

#define MSG_ID_WIFI_SSID                "WIFI/SSID"
#define MSG_ID_WIFI_PASSWORD            "WIFI/PASSWORD"

/* Battery 电池状态消息 */
#define MSG_BATTERY_UPDATE_DURATION     (60 * 1000)
#define MSG_ID_BATTERY_STATUS           "BATTERY/STATUS"
#define MSG_CONTENT_BATTERY_CHARGING    "CHARGING"
#define MSG_CONTENT_BATTERY_DISCHARGING "DISCHARGING"

/* Battery 电池百分比消息 */
#define MSG_ID_BATTERY_PERCENT          "BATTERY/PERCENT"

/* 系统启动时长消息 */
#define MSG_ID_SYSTEM_START_DURATION    "SYSTEM/START_DURATION"

/* 系统 APP 数量消息 */
#define MSG_ID_SYSTEM_APP_NUM           "SYSTEM/APP_NUM"

/* 系统 APP 状态栏标题 */
#define MSG_ID_SYSTEM_APP_TITLE         "SYSTEM/APP_TITLE"

/* 系统时间消息 */
#define MSG_ID_TIME_HM                  "TIME/HM"
#define MSG_ID_TIME_SEC                 "TIME/SEC"
#define MSG_ID_TIME_WDAY                "TIME/WDAY"
#define MSG_ID_TIME_DAY                 "TIME/DAY"

using namespace std;

typedef struct {
    String sub_cb_name;                 /* 订阅者回调函数唯一名称 */
    function<void(String)> sub_cb;      /* 消息发布时订阅者回调函数 */
} SubscriberFunc;

typedef struct {
    /* 消息缓存池 */
    unordered_map<string, string> pub_msg_buf;                      /* id = content */
    unordered_map<string, vector<SubscriberFunc>> sub_msg_buf;      /* id = func */
} Message_Pool;

extern Message_Pool MessagePool;

#endif // ATOM_UI_LV9_MESSAGE_POOL_H
