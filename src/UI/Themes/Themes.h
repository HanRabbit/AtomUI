#ifndef ATOM_UI_LV9_THEMES_H
#define ATOM_UI_LV9_THEMES_H

#include <Arduino.h>
#include <lvgl.h>

#define ATOM_THEME_BG_COLOR 0x000000

void lv_obj_add_anim(
        lv_obj_t * obj, lv_anim_t * a,
        lv_anim_exec_xcb_t exec_cb,
        int32_t start, int32_t end,
        uint16_t time,
        lv_anim_ready_cb_t ready_cb,
        lv_anim_path_cb_t path_cb
);


#endif // ATOM_UI_LV9_THEMES_H
