#include "TimerManager.h"

void TimerManager::init() const {
    /* 链表初始化 */
    t_head->t_next = nullptr;
}

/**
 * @brief 定时器组注册函数
 * @param timer_xcb 定时器回调函数
 * @param period 定时器重复执行时间
 * @param timer_name 定时器名称
 * @param user_data 用户数据
 * @param auto_del 是否自动删除定时器
 * @return 定时器id
 */
uint8_t TimerManager::t_register(lv_timer_cb_t t_xcb, uint32_t period, const char *t_name, void *user_data, bool auto_del) {
    /* 使用链表结构存储 timer 结构体指针，便于动态分配 */
    t_p = (timer_group_t *) malloc(sizeof(timer_group_t));

    /* 调用 lvgl 自带的定时器进行初始化 */
    t_p->timer  = lv_timer_create(t_xcb, period, user_data);
    t_p->name   = t_name;
    t_p->id     = cur_timer_num;

    t_tail->t_next = t_p;
    t_tail = t_p;
    t_tail->t_next = nullptr;

    /* 自动删除定时器 */
    lv_timer_set_auto_delete(t_p->timer, auto_del);

    /* 返回当前 id 之后自增 1 */
    return cur_timer_num ++;
}

timer_group_t *TimerManager::t_seek(const char *t_name) {
    t_p = t_head;
    while (t_p != nullptr) {
        if (t_p->name == t_name)
            return t_p;

        t_p = t_p->t_next;
    }
    return nullptr;
}

timer_group_t *TimerManager::t_seek(uint8_t t_id) {
    t_p = t_head;
    while (t_p != nullptr) {
        if (t_p->id == t_id)
            return t_p;

        t_p = t_p->t_next;
    }
    return nullptr;
}

void TimerManager::t_delete(const char *t_name) {
    timer_group_t *t = t_seek(t_name);
    /* 匹配 timer 名称 */
    lv_timer_delete(t->timer);

    /* 将其上一指针指向其下一指针后释放该指针内存，实现删除 */
    t_seek(t_p->id - 1)->t_next = t_seek(t_p->id + 1);

    /* 释放内存 */
    delete &t;

    t_p = t_head;

    cur_timer_num --;

    /* 没有找到匹配计时器名称 */
    LV_LOG_ERROR("Delete timer: %s failed, didn't find timer name", t_name);
}
