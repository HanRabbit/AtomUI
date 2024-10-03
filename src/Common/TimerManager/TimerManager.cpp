#include "TimerManager.h"

Timer_Manager TimerManager;

/**
 * @brief 定时器组注册函数
 * @param timer_xcb 定时器回调函数
 * @param period 定时器重复执行时间
 * @param timer_name 定时器名称
 * @param user_data 用户数据
 * @param auto_del 是否自动删除定时器
 * @return 定时器id
 */
uint8_t Timer_Manager::t_register(lv_timer_cb_t t_xcb, uint32_t period, const char *t_name, void *user_data, bool auto_del) {
    tm_timer_t tm_reg_timer;
    tm_reg_timer.name = t_name;
    tm_reg_timer.id = timer_group.size();

    lv_timer_create(t_xcb, period, user_data);

    timer_group.push_back(tm_reg_timer);

    return 0;
}

tm_timer_t Timer_Manager::t_seek(const char *t_name) {
    for (auto timer_item: timer_group) {
        if (timer_item.name == t_name)
            return timer_item;
    }
}

tm_timer_t Timer_Manager::t_seek(uint8_t t_id) {
    for (auto timer_item: timer_group) {
        if (timer_item.id == t_id)
            return timer_item;
    }
}

void Timer_Manager::t_delete(const char *t_name) {
    tm_timer_t tm_timer = t_seek(t_name);
    lv_timer_delete(tm_timer.timer);
    timer_group.erase(timer_group.begin() + tm_timer.id);
}
