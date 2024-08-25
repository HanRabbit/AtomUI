#include "PageManager.h"

PageManager Page_Manager;

/**
 * @brief 页面管理器初始化
 */
void PageManager::init() const {
    p_head->next = nullptr;
}

/**
 * @brief 页面注册
 * @param name 页面名称
 * @param p_create 页面创建方法
 * @param p_delete 页面删除方法
 */
void PageManager::p_register(const char *name, lv_obj_t *(*p_create)(), lv_obj_t *(*p_delete)()) {
    /* 申请内存 */
    p = (Page *) malloc(sizeof(Page));

    p->p_name   = name;
    p->p_id     = pages_num;
    p->p_create = p_create;
    p->p_delete = p_delete;

    /* 调用 Page 类中的页面初始化 */
    p->p_init(name, pages_num, p_create, p_delete);

    /* 向链表末尾添加 Page 元素 */
    p_tail->next = p;
    p_tail = p;
    p_tail->next = nullptr;

    pages_num ++;
}

/**
 * @brief 通过页面 ID 查找
 * @param id 页面唯一 ID
 * @return 页面类
 */
Page *PageManager::p_seek(uint16_t id) {
    p = p_head;
    while (p != nullptr) {
        if (p->p_id == id) return p;
    }
    return nullptr;
}

/**
 * @brief 通过页面名称查找
 * @param name 页面名称
 * @return 页面类
 */
Page *PageManager::p_seek(const char *name) {
    p = p_head;
    while (p != nullptr) {
        if (p->p_name == name) return p;
    }
    return nullptr;
}

void PageManager::p_push(const char *name) {
    Page *page = p_seek(name);

    /* 判断是否为首页面 */
    if (pages_num != 0) {
        Page *p_pre = p_seek(p->p_id - 1);

        p_pre->p_delete();
    }

    if (page != nullptr) {
        lv_screen_load(p_seek(name)->p_load());
    } else {
        LV_LOG_ERROR("page: %s is not found", name);
    }
}

void PageManager::p_push(const char *name, ScreenAnim anim) {
    Page *page = p_seek(name);

    /* 判断是否为首页面 */
    if (pages_num != 0) {
        Page *p_pre = p_seek(p->p_id - 1);
        p_pre->p_delete();
    }

    if (page != nullptr) {
        lv_screen_load_anim(p_seek(name)->p_load(), anim.anim_type, anim.time, anim.delay, true);
    } else {
        LV_LOG_ERROR("page: %s is not found", name);
    }
}

void PageManager::p_delete(uint16_t id) {
    Page *p_pre = p_seek(p->p_id - 1);
    Page *p_cur = p_seek(id);

    /* 删除页面 */
    p_cur->p_delete();

    if (p_pre != nullptr)
        p_pre->next = p_cur->next;

    free(p_cur);

    pages_num --;
}

void PageManager::p_delete(const char *name) {
    Page *p_pre = p_seek(p->p_id - 1);
    Page *p_cur = p_seek(name);

    /* 删除页面 */
    p_cur->p_delete();

    if (p_pre != nullptr)
        p_pre->next = p_cur->next;

    free(p_cur);

    pages_num --;
}
