#ifndef ATOM_UI_LV9_SUBSCRIBER_H
#define ATOM_UI_LV9_SUBSCRIBER_H

#include <Arduino.h>

using namespace std;

class Subscriber {
public:
    void subcribe(const String& id, function<void(String)> sub_cb);
};

extern Subscriber subscriber;

#endif // ATOM_UI_LV9_SUBSCRIBER_H
