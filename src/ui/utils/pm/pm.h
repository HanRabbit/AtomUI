#ifndef ATOM_UI_PM_H
#define ATOM_UI_PM_H

#include <lvgl.h>
#include "ui/pages/page.h"

typedef struct ScrAnim {
public:
    lv_scr_load_anim_t anim_type;
    uint32_t time;
    uint32_t delay;
} ScrAnim;

static ScrAnim PM_SCR_ANIM_OVER_TOP = {LV_SCR_LOAD_ANIM_OVER_TOP, 400, 0};
static ScrAnim PM_SCR_ANIM_MOVE_TOP = {LV_SCR_LOAD_ANIM_MOVE_TOP, 400, 0};
static ScrAnim PM_SCR_ANIM_OVER_BOTTOM = {LV_SCR_LOAD_ANIM_OVER_BOTTOM, 400, 0};
static ScrAnim PM_SCR_ANIM_MOVE_BOTTOM = {LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 400, 0};
static ScrAnim PM_SCR_ANIM_FADE_ON = {LV_SCR_LOAD_ANIM_FADE_ON, 200, 0};
static ScrAnim PM_SCR_ANIM_MOVE_LEFT = {LV_SCR_LOAD_ANIM_MOVE_LEFT, 400, 0};
static ScrAnim PM_SCR_ANIM_MOVE_RIGHT = {LV_SCR_LOAD_ANIM_MOVE_RIGHT, 400, 0};

class PageManager {
    Page pages[20];
    uint16_t max_id = 0;
    uint16_t current_page = 0;

public:
    uint16_t get_id(const char *name);
    void pm_register(Page page);
    void add_page(const char *name, lv_obj_t *(*create_func)(), lv_obj_t *(*delete_func)());
    void push(const char *name, ScrAnim scrAnim);
    void push(const char *name);
};

#endif //ATOM_UI_PM_H
