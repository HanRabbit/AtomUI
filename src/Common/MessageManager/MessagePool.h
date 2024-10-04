#ifndef ATOM_UI_LV9_MESSAGE_POOL_H
#define ATOM_UI_LV9_MESSAGE_POOL_H

#include <Arduino.h>
#include <unordered_map>
#include <vector>

using namespace std;

typedef struct {
    /* 消息缓存池 */
    unordered_map<string, string> pub_msg_buf;                      /* id = content */
    unordered_map<string, vector<function<void(String)>>> sub_msg_buf;      /* id = func */
} Message_Pool;

extern Message_Pool MessagePool;

#endif // ATOM_UI_LV9_MESSAGE_POOL_H
