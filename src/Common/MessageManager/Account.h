#ifndef ATOM_UI_LV9_ACCOUNT_H
#define ATOM_UI_LV9_ACCOUNT_H

#include <Arduino.h>
#include <unordered_map>

using namespace std;

class Publisher {
public:
    void publish(const String& id, const String &content);
};

class Subscriber {
public:
    void subcribe(const String& id, function<void(String)> sub_cb);
};

extern Subscriber subscriber;
extern Publisher publisher;

#endif // ATOM_UI_LV9_ACCOUNT_H
