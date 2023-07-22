#ifndef ATOM_UI_LOG_H
#define ATOM_UI_LOG_H

#include <Arduino.h>
#include "error_codes.h"

#define LOG_IS_USE_SERIAL 1

#if LOG_IS_USE_SERIAL
#define LOG_ USBSerial

static String LOG_NAME_DEFAULT = "Atom";

class Log {
public:
    static void error(const String& err);
    static void error(const String& name, const String& err);

    static void msg(const String& msg);
    static void msg(const String& name, const String& msg);

    static void begin(unsigned long baud);

    static String read();
};

#endif

#endif //ATOM_UI_LOG_H
