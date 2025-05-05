#include "Pages.h"

/**
 * @brief 页面初始化
 * @param name 页面名称
 * @param id 页面唯一 ID
 * @param m_create 创建页面方法
 * @param m_delete 删除页面方法
 */
void Page::p_init(const char *name, uint16_t id, lv_obj_t *(*m_create)(), lv_obj_t *(*m_delete)()) {
    p_name   = name;
    p_id     = id;
    p_create = m_create;
    p_delete = m_delete;
}

/**
 * @brief 显示页面
 * @return 页面根
 */
lv_obj_t *Page::p_load() {
    p_screen = p_create();
    return p_screen;
}

/**
 * @brief 页面删除
 */
void Page::p_del() const {
    p_delete();
}