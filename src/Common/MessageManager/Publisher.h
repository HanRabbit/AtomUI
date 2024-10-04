#ifndef ATOM_UI_LV9_MESSAGE_MANAGER_H
#define ATOM_UI_LV9_MESSAGE_MANAGER_H

#include <Arduino.h>
#include <unordered_map>

using namespace std;

class Publisher {
public:
    void publish(const String& id, const String &content);
};

extern Publisher publisher;

#endif // ATOM_UI_LV9_MESSAGE_MANAGER_H
