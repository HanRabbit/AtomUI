#include "log.h"

void Log::error(const String& err) {
    LOG_.println("[ERROR] " + err);
}

void Log::error(const String& name, const String& err) {
    LOG_.println("[ERROR] " + name + ": " + err);
}

void Log::msg(const String& msg) {
    LOG_.println("[MESSAGE] " + msg);
}

void Log::msg(const String &name, const String &msg) {
    LOG_.println("[MESSAGE] " + name + ": " + msg);
}

void Log::begin(unsigned long baud) {
    LOG_.begin(baud);
}

String Log::read() {
    return LOG_.readString();
}
