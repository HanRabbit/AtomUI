#ifndef ATOM_UI_LV9_TIMER_MANAGER_H
#define ATOM_UI_LV9_TIMER_MANAGER_H

#include <Arduino.h>
#include <lvgl.h>

/* 定时器组结构体 */
struct TimerGroup{
    lv_timer_t *timer;
    const char *name;
    uint8_t id;

    struct TimerGroup *t_next;
} typedef timer_group_t;

/* 定时器管理器 */
class TimerManager {
public:
    /* 定时器数组 */
    timer_group_t *t_p = (timer_group_t *) malloc(sizeof(timer_group_t));
    timer_group_t *t_head = t_p;
    timer_group_t *t_tail = t_p;

    /* 当前定时器数量 */
    uint8_t cur_timer_num = 0;

    void init() const;

    /* 定时器操作 */
    uint8_t t_register(lv_timer_cb_t t_xcb, uint32_t period, const char *t_name, void *user_data, bool auto_del);

    timer_group_t *t_seek(const char *t_name);
    timer_group_t *t_seek(uint8_t t_id);

    void t_delete(const char *t_name);
};

#endif // ATOM_UI_LV9_TIMER_MANAGER_H
