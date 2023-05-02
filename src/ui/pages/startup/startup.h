#ifndef ATOM_UI_STARTUP_H
#define ATOM_UI_STARTUP_H

#include <lvgl.h>
#include "ui/utils/ui_utils.h"

class StartupPage {
public:
    static void ui_event(lv_event_t *e);

    static lv_obj_t *page_delete();
    static lv_obj_t *page_create();
};

#endif //ATOM_UI_STARTUP_H