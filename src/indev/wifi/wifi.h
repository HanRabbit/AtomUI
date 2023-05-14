#ifndef ATOM_UI_WIFI_H
#define ATOM_UI_WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <lvgl.h>

static const char *WIFI_SSID = "U-home";
static const char *WIFI_PASSWORD = "MyHome_16$5334783";

void wifi_init();

void wifi_status_update(lv_timer_t *timer);

#endif //ATOM_UI_WIFI_H
