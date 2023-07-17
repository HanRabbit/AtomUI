#ifndef ATOM_UI_WIFI_H
#define ATOM_UI_WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <lvgl.h>
#include "common/time/time.h"

static const char *WIFI_SSID = "U-home";
static const char *WIFI_PASSWORD = "MyHome_16$5334783";

static const char *ntp_server = "pool.ntp.org";
static const long gmt_offset_sec = 8 * 3600;
static const uint8_t day_light_offset_sec = 0;

static bool time_has_been_corrected = false;

static String WiFi_MODE;

typedef enum {
    WIFI_CONNECTED,
    WIFI_CLOSED
} wifi_icon_t;

void wifi_init();

bool get_wifi_status();

void wifi_set_time();

#endif //ATOM_UI_WIFI_H
