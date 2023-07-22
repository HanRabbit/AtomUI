#ifndef ATOM_UI_SERIAL_MONITOR_H
#define ATOM_UI_SERIAL_MONITOR_H

#include <lvgl.h>
#include "common/log/log.h"

#define SERIAL_READ_FREQUENT 200

class SerialMonitorPage {

public:
    static lv_obj_t *page_delete();

    static lv_obj_t *page_create();
};

#endif //ATOM_UI_SERIAL_MONITOR_H
