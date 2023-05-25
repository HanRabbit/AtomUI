#ifndef ATOM_UI_HOME_EVENTS_H
#define ATOM_UI_HOME_EVENTS_H

#include "lvgl.h"
//#include <src/extra/others/msg/lv_msg.h>
#include <Arduino.h>
#include "ui/utils/ui_utils.h"
#include "common/time/time.h"

void battery_status_show(lv_timer_t *timer);

void ui_event(lv_event_t *e);

void ui_events_handle();

#endif //ATOM_UI_HOME_EVENTS_H
