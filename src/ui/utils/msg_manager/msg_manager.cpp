#include "msg_manager.h"

void MsgManager::send_msg(String key, String value) {
    if (msg_num > MSG_MANAGER_MAX_MSG) {
        Log::error("MsgManager", "Messages went beyond MSG_MANAGER_MAX_MSG");
        return;
    } else {
        messages[msg_num].msg_key = key;
        messages[msg_num++].msg_value_string = value;
    }
}

String MsgManager::get_msg(String key) {
    for (int i = 0; i < msg_num; i ++) {
        if (messages[i].msg_key == key) {
            return messages[i].msg_value_string;
        }
    }
    return "";
}

String MsgManager::get_msg(uint16_t id) {
    return messages[id].msg_value_string;
}

