// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.2.0
// Project name: atom_ui

#ifndef _ATOM_UI_UI_H
#define _ATOM_UI_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"
void anim_down_Animation(lv_obj_t * TargetObject, int delay);
void anim_zoom_fade_out_Animation(lv_obj_t * TargetObject, int delay);
void side_bar_spread_Animation(lv_obj_t * TargetObject, int delay);
// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
extern lv_obj_t * ui_Screen2;
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_Label9;
extern lv_obj_t * ui_Label10;
extern lv_obj_t * ui_Label11;
extern lv_obj_t * ui_Label12;
// SCREEN: ui_Screen3
void ui_Screen3_screen_init(void);
extern lv_obj_t * ui_Screen3;
extern lv_obj_t * ui_Panel6;
extern lv_obj_t * ui_Panel5;
extern lv_obj_t * ui_statusBar1;
extern lv_obj_t * ui_wifiMode1;
extern lv_obj_t * ui_wifiIcon1;
extern lv_obj_t * ui_atomLabel1;
extern lv_obj_t * ui_batteryIcon1;
extern lv_obj_t * ui_Label8;
extern lv_obj_t * ui_timePanel1;
extern lv_obj_t * ui_hourMinPanel1;
extern lv_obj_t * ui_minRoller3;
extern lv_obj_t * ui_minRoller4;
extern lv_obj_t * ui_Label14;
extern lv_obj_t * ui_hourRoller3;
extern lv_obj_t * ui_hourRoller4;
extern lv_obj_t * ui_Bar1;
extern lv_obj_t * ui_Label15;
extern lv_obj_t * ui_Label16;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_Image5;
extern lv_obj_t * ui_Label17;
extern lv_obj_t * ui_Image6;
extern lv_obj_t * ui_Label18;
extern lv_obj_t * ui_Image7;
extern lv_obj_t * ui_Label19;
extern lv_obj_t * ui_Image8;
extern lv_obj_t * ui_Label20;
extern lv_obj_t * ui_Panel7;
extern lv_obj_t * ui_Button2;
extern lv_obj_t * ui_Image2;
extern lv_obj_t * ui____initial_actions0;

LV_IMG_DECLARE(ui_img_wifi_closed_png);    // assets\WIFI_CLOSED.png
LV_IMG_DECLARE(ui_img_battery_png);    // assets\BATTERY.png
LV_IMG_DECLARE(ui_img_link_png);    // assets\LINK.png
LV_IMG_DECLARE(ui_img_time_png);    // assets\TIME.png
LV_IMG_DECLARE(ui_img_follows_png);    // assets\FOLLOWS.png
LV_IMG_DECLARE(ui_img_settings_png);    // assets\SETTINGS.png
LV_IMG_DECLARE(ui_img_power_2_png);    // assets\POWER_2.png

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
