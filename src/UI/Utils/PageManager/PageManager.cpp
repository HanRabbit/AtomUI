#include "PageManager.h"
#include "Drivers/Display/Display.h"

Page_Manager PageManager;

/**
 * @brief 页面管理器初始化
 */
void Page_Manager::init() const {
    p_head->next = nullptr;
}

/**
 * @brief 页面注册
 * @param name 页面名称
 * @param p_create 页面创建方法
 * @param p_delete 页面删除方法
 */
void Page_Manager::p_register(const char *name, lv_obj_t *(*create)(), lv_obj_t *(*del)()) {
    /* 申请内存 */
    p = (Page *) malloc(sizeof(Page));

    /* 调用 Page 类中的页面初始化 */
    p->p_init(name, pages_num, create, del);

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
Page *Page_Manager::p_seek(uint16_t id) {
    p = p_head;
    while (p != nullptr) {
        if (p->p_id == id) return p;
        p = p->next;
    }
    return nullptr;
}

/**
 * @brief 通过页面名称查找
 * @param name 页面名称
 * @return 页面类
 */
Page *Page_Manager::p_seek(const char *name) {
    p = p_head;
    while (p != nullptr) {
        if (p->p_name == name) return p;
        p = p->next;
    }
    return nullptr;
}

void Page_Manager::p_push(const char *name) {
    Page *page = p_seek(name);

    if (page != nullptr) {
        lv_screen_load_anim(page->p_load(), LV_SCR_LOAD_ANIM_NONE, 0, 0, true);

        /* 判断是否为首页面 */
        if (pages_num != 0 && !first_push) {
            Page *p_pre = p_seek(cur_page);
            p_pre->p_delete();
            cur_page = page->p_id;
        }

        cur_page = page->p_id;
        first_push = false;
    } else {
        LV_LOG_ERROR("page: %s is not found", name);
    }
}

void Page_Manager::p_push(const char *name, ScreenAnim anim) {
    Page *page = p_seek(name);

    if (page != nullptr) {
        lv_screen_load_anim(page->p_load(), anim.anim_type, anim.time, anim.delay, true);

        /* 判断是否为首页面 */
        if (pages_num != 0 && !first_push) {
            Page *p_pre = p_seek(cur_page);
            p_pre->p_delete();
            cur_page = page->p_id;
        }

        cur_page = page->p_id;
        first_push = false;
    } else {
        LV_LOG_ERROR("page: %s is not found", name);
    }
}

void Page_Manager::p_push_black_fade(const char *name) {
    Page *page = p_seek(name);

    if (page != nullptr) {
        TFT_BackLight.set_BL_brightness(0);

        lv_screen_load_anim(page->p_load(), LV_SCR_LOAD_ANIM_NONE, 0, 700, true);

        lv_timer_create([] (lv_timer_t *timer) {
            Page *page_inside = (Page *) timer->user_data;
            TFT_BackLight.set_BL_brightness(BL_DEFAULT);
            lv_timer_delete(timer);
        }, 800, page);

        /* 判断是否为首页面 */
        if (pages_num != 0 && !first_push) {
            Page *p_pre = p_seek(cur_page);
            p_pre->p_delete();
            cur_page = page->p_id;
        }

        cur_page = page->p_id;
        first_push = false;
    } else {
        LV_LOG_ERROR("page: %s is not found", name);
    }
}

void Page_Manager::p_delete(uint16_t id) {
    Page *p_pre = p_seek(cur_page);
    Page *p_cur = p_seek(id);

    /* 删除页面 */
    p_cur->p_delete();

    if (p_pre != nullptr)
        p_pre->next = p_cur->next;

    free(p_cur);

    pages_num --;
}

void Page_Manager::p_delete(const char *name) {
    Page *p_pre = p_seek(cur_page);
    Page *p_cur = p_seek(name);

    /* 删除页面 */
    p_cur->p_delete();

    if (p_pre != nullptr)
        p_pre->next = p_cur->next;

    free(p_cur);

    pages_num --;
}

