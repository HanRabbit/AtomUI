#ifndef ATOM_UI_LV9_PAGE_MANAGER_H
#define ATOM_UI_LV9_PAGE_MANAGER_H

#include <Arduino.h>
#include <lvgl.h>
#include "UI/Res/Pages/Pages.h"

/* 屏幕切换动画结构体 */
typedef struct ScreenAnim {
public:
    lv_scr_load_anim_t anim_type;       /* 屏幕切换动画类型 */
    uint32_t time;                      /* 动画时间 */
    uint32_t delay;                     /* 动画延时 */
} ScrAnim;

class PageManager {
public:
    Page *p = (Page *) malloc(sizeof(Page));
    Page *p_tail = p;
    Page *p_head = p;

    uint16_t pages_num = 0;

    void init() const;

    void p_register(const char *name, lv_obj_t *(*p_create)(), lv_obj_t *(*p_delete)());

    Page *p_seek(const char *name);
    Page *p_seek(uint16_t id);

    void p_push(const char *name);
    void p_push(const char *name, ScreenAnim anim);

    void p_delete(const char *name);
    void p_delete(uint16_t id);
};

extern PageManager Page_Manager;

#endif // ATOM_UI_LV9_PAGE_MANAGER_H
