#ifndef ATOM_UI_LV9_TIMER_MANAGER_H
#define ATOM_UI_LV9_TIMER_MANAGER_H

#include <Arduino.h>
#include <vector>
#include <lvgl.h>

/* 定时器组结构体 */
struct tm_timer_t {
    lv_timer_t *timer;
    const char *name;
    uint8_t id;
} typedef tm_timer_t;

/* 定时器管理器 */
class Timer_Manager {
public:
    /* 使用 Vector 动态数组存储定时器信息 */
    std::vector<tm_timer_t> timer_group;

    /* 定时器操作 */
    uint8_t t_register(lv_timer_cb_t t_xcb, uint32_t period, const char *t_name, void *user_data, bool auto_del);

    tm_timer_t t_seek(const char *t_name);
    tm_timer_t t_seek(uint8_t t_id);

    void t_delete(const char *t_name);
};

extern Timer_Manager TimerManager;

#endif // ATOM_UI_LV9_TIMER_MANAGER_H
