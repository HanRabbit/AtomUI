#ifndef ATOM_UI_STATUS_BAR_H
#define ATOM_UI_STATUS_BAR_H

#include <lvgl.h>
#include <WiFi.h>
#include "ui/res/rp/rp.h"

#define STATUS_BAR_UPDATE_DURING 1000

typedef enum {CONNECTED = true, DISCONNECTED = false} wifi_status_t;

class Status {
public:
    wifi_mode_t wifi_mode = WIFI_MODE_NULL;     /* WiFi模式 */
    wifi_status_t wifi_status = DISCONNECTED;
    String battery = "";             /* 电池状态（百分比） */
    String title = "";                /* 标题 */
};

class StatusBar {
public:
    Status status;
    int margin_y = -10;
    lv_obj_t *ui_back_button{}, *ui_back_icon{}, *ui_wifi_icon{}, *ui_wifi_mode{}, *ui_info_label{}, *ui_battery_perc_label{}, *ui_battery_icon{};
    lv_timer_t *status_bar_timer{};

    void create_status_bar(lv_obj_t *root);
    void update();
    void set_title(String st);
    void get_battery();
};

#endif //ATOM_UI_STATUS_BAR_H
