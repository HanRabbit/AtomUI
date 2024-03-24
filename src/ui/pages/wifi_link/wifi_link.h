#ifndef ATOM_UI_WIFI_LINK_H
#define ATOM_UI_WIFI_LINK_H

#include <lvgl.h>
#include <WString.h>

class WiFiLinkPage {
public:
    static lv_obj_t *page_delete();

    static lv_obj_t *page_create();
};

#endif //ATOM_UI_WIFI_LINK_H
