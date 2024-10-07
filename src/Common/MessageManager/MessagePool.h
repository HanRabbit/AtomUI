#ifndef ATOM_UI_LV9_MESSAGE_POOL_H
#define ATOM_UI_LV9_MESSAGE_POOL_H

#include <Arduino.h>
#include <unordered_map>
#include <vector>

/* WiFi 消息状态 */
#define MSG_ID_WIFI_STATUS              "WIFI/STATUS"
#define MSG_CONTENT_WIFI_CONNECTED      "CONNECTED"
#define MSG_CONTENT_WIFI_DISCONNECTED   "DISCONNECTED"

/* Battery 电池状态消息 */
#define MSG_BATTERY_UPDATE_DURATION     (60 * 1000)
#define MSG_ID_BATTERY_STATUS           "BATTERY/STATUS"
#define MSG_CONTENT_BATTERY_CHARGING    "CHARGING"
#define MSG_CONTENT_BATTERY_DISCHARGING "DISCHARGING"

/* Battery 电池百分比消息 */
#define MSG_ID_BATTERY_PERCENT          "BATTERY/PERCENT"

/* 系统启动时长消息 */
#define MSG_ID_SYSTEM_START_DURATION    "SYSTEM/START_DURATION"

/* 系统时间消息 */
#define MSG_ID_TIME_HM                  "TIME/HM"
#define MSG_ID_TIME_SEC                 "TIME/SEC"

using namespace std;

typedef struct {
    /* 消息缓存池 */
    unordered_map<string, string> pub_msg_buf;                              /* id = content */
    unordered_map<string, vector<function<void(String)>>> sub_msg_buf;      /* id = func */
} Message_Pool;

extern Message_Pool MessagePool;

#endif // ATOM_UI_LV9_MESSAGE_POOL_H
