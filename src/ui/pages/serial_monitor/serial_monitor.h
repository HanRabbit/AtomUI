#ifndef ATOM_UI_SERIAL_MONITOR_H
#define ATOM_UI_SERIAL_MONITOR_H

#include <lvgl.h>

class SerialMonitorPage {

public:
    static lv_obj_t *page_delete();

    static lv_obj_t *page_create();
};

#endif //ATOM_UI_SERIAL_MONITOR_H
