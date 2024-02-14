#ifndef ATOM_UI_MSG_POOL_H
#define ATOM_UI_MSG_POOL_H

#include "Arduino.h"

class Message {
public:
    uint16_t msg_size{};
    uint16_t msg_id{};
    String msg_key{};
    String msg_value_string{};
};


#endif //ATOM_UI_MSG_POOL_H
