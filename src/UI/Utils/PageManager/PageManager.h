#ifndef ATOM_UI_LV9_PAGE_MANAGER_H
#define ATOM_UI_LV9_PAGE_MANAGER_H

#include <Arduino.h>
#include "UI/Res/Pages/Pages.h"
#include "Drivers/Display/TFT_backlight/TFT_backlight.h"
#include "lvgl.h"

/* 默认动画时间 */
#define SCREEN_DEFAULT_ANIM_TIME 400

/* 屏幕切换动画结构体 */
typedef struct ScreenAnim {
public:
    lv_scr_load_anim_t anim_type;       /* 屏幕切换动画类型 */
    uint32_t time;                      /* 动画时间 */
    uint32_t delay;                     /* 动画延时 */
} ScreenAnim;

static ScreenAnim PM_SCR_ANIM_OVER_TOP = {LV_SCR_LOAD_ANIM_OVER_TOP, SCREEN_DEFAULT_ANIM_TIME, 0};
static ScreenAnim PM_SCR_ANIM_MOVE_TOP = {LV_SCR_LOAD_ANIM_MOVE_TOP, SCREEN_DEFAULT_ANIM_TIME, 0};
static ScreenAnim PM_SCR_ANIM_OVER_BOTTOM = {LV_SCR_LOAD_ANIM_OVER_BOTTOM, SCREEN_DEFAULT_ANIM_TIME, 0};
static ScreenAnim PM_SCR_ANIM_MOVE_BOTTOM = {LV_SCR_LOAD_ANIM_MOVE_BOTTOM, SCREEN_DEFAULT_ANIM_TIME, 0};
static ScreenAnim PM_SCR_ANIM_FADE_ON = {LV_SCR_LOAD_ANIM_FADE_ON, SCREEN_DEFAULT_ANIM_TIME, 0};
static ScreenAnim PM_SCR_ANIM_MOVE_LEFT = {LV_SCR_LOAD_ANIM_MOVE_LEFT, SCREEN_DEFAULT_ANIM_TIME, 0};
static ScreenAnim PM_SCR_ANIM_MOVE_RIGHT = {LV_SCR_LOAD_ANIM_MOVE_RIGHT, SCREEN_DEFAULT_ANIM_TIME, 0};

class Page_Manager {
    bool first_push = true;
public:
    Page *p = (Page *) malloc(sizeof(Page));
    Page *p_tail = p;
    Page *p_head = p;

    uint16_t pages_num = 0;
    uint16_t cur_page = 0;

    void init() const;

    void p_register(const char *name, lv_obj_t *(*create)(), lv_obj_t *(*del)());

    Page *p_seek(const char *name);
    Page *p_seek(uint16_t id);

    void p_push(const char *name);
    void p_push(const char *name, ScreenAnim anim);

    void p_delete(const char *name);
    void p_delete(uint16_t id);
    void p_push_black_fade(const char *name);
};

extern Page_Manager PageManager;

#endif // ATOM_UI_LV9_PAGE_MANAGER_H
