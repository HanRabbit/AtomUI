#ifndef ATOM_UI_LV9_TIMER_MANAGER_H
#define ATOM_UI_LV9_TIMER_MANAGER_H

#include <Arduino.h>
#include <lvgl.h>

/* 最大允许的定时器数量 */
#define TIMER_MAX_NUM 20

/* 定时器管理器 */
class TimerManager {
public:
    /* 定时器数组 */
    lv_timer_t timers_arr[TIMER_MAX_NUM];

    /* 当前定时器数量 */
    uint8_t current_timer_num = 0;

    /* 定时器操作 */
    void timer_add(lv_timer_cb_t timer_xcb, uint32_t period, void * user_data);

};

#endif // ATOM_UI_LV9_TIMER_MANAGER_H
