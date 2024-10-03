#ifndef ATOM_UI_LV9_MESSAGE_MANAGER_H
#define ATOM_UI_LV9_MESSAGE_MANAGER_H

#include <Arduino.h>
#include <lvgl.h>
#include <unordered_map>
#include "Common/TimerManager/TimerManager.h"

#define MESSAGE_CALLBACK_DURATION 1000

using namespace std;

/* 消息发布订阅管理 */
/* 格式为 'Key' = 'Value' */

class Message_Manager {
    /* 建立消息 HashMap */
    unordered_map<string, string> message_map;

    /* 建立 HashMap 迭代器 */
    unordered_map<string, string>::iterator iterator;

    struct message_t {
        String key;
        void (*cb) (String);
    } typedef message_t;

public:
    /* 发布消息 */
    void publish(String key, String value);

    /* 直接获取消息 */
    String get(String key);

    void subscribe(String key, void (*cb) (String));
};

extern Message_Manager MessageManager;

#endif // ATOM_UI_LV9_MESSAGE_MANAGER_H
