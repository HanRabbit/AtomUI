#ifndef ATOM_UI_LV9_ACCOUNT_H
#define ATOM_UI_LV9_ACCOUNT_H

#include <Arduino.h>
#include "Common/MessageManager/MessagePool.h"

using namespace std;

/* 消息发布类 */
class Publisher {
public:
    void publish(const String& id, const String &content);
};

/* 消息订阅类 */
class Subscriber {
public:
    void subscribe(const String& id, const SubscriberFunc& subscriber_func);
    void subscribe_clear(const String& id);
    void unsubscribe(const String& id, const String& sub_cb_name);
};

extern Subscriber subscriber;
extern Publisher publisher;

#endif // ATOM_UI_LV9_ACCOUNT_H
