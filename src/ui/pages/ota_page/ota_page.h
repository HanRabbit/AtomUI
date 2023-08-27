#ifndef ATOM_UI_TEST_H
#define ATOM_UI_TEST_H

#include <lvgl.h>
#include "indev/indev.h"
#include "common/ota_update/ota_update.h"

class OTAPage {
    static void ui_event(lv_event_t *e);
public:
    static lv_obj_t *page_delete();

    static lv_obj_t *page_create();
};

#endif //ATOM_UI_TEST_H
