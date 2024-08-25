#ifndef ATOM_UI_LV9_PAGES_H
#define ATOM_UI_LV9_PAGES_H

#include <Arduino.h>
#include <lvgl.h>

class Page {
public:
    const char *p_name;     /* 页面名称 */
    uint16_t p_id;          /* 页面唯一 id */

    lv_obj_t *(*p_create)();        /* 页面创建方法 */
    lv_obj_t *(*p_delete)();        /* 页面删除方法 */

    /* 页面初始化 */
    void p_init(const char *name, uint16_t id, lv_obj_t *(*m_create)(), lv_obj_t *(*m_delete)());

    /* 调用页面 */
    lv_obj_t *p_load() const;

    /* 页面删除 */
    void p_del() const;

    Page *next;
};

#endif // ATOM_UI_LV9_PAGES_H
