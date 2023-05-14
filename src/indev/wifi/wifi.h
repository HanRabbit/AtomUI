#ifndef ATOM_UI_WIFI_H
#define ATOM_UI_WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <lvgl.h>

static const char *WIFI_SSID = "U-home";
static const char *WIFI_PASSWORD = "MyHome_16$5334783";

static const char *ntp_server = "pool.ntp.org";
static const long gmt_offset_sec = 8 * 3600;
static const uint8_t day_light_offset_sec = 0;

static bool time_has_been_corrected = false;

static String WiFi_MODE;

void wifi_init();

void wifi_status_update(lv_timer_t *timer);

void wifi_set_time();

#endif //ATOM_UI_WIFI_H
