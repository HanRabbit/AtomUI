#ifndef ATOM_UI_MSG_MANAGER_H
#define ATOM_UI_MSG_MANAGER_H

#include <Arduino.h>
#include "msg_pool.h"
#include "common/log/log.h"

#define MSG_MANAGER_MAX_MSG 20

class MsgManager {
    Message messages[MSG_MANAGER_MAX_MSG];
public:
    uint16_t msg_num = 0;
    void send_msg(String key, String value);
    void send_msg(String key, uint16_t value);

    String get_msg(String key);
    String get_msg(uint16_t id);
};


#endif //ATOM_UI_MSG_MANAGER_H
