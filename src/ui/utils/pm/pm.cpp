#include "pm.h"


/**
 * @brief 通过Page name查找获取Page id
 * @param name: Page name
 * @return -1: None
 * @return id: Page id
 */
uint16_t PageManager::get_id(const char *name) {
    for (int id = 0; id < max_id; id ++) {
        if (pages[id].p_name == name) {
            return id;
        }
    }
    return -1;
}

/**
 * @brief 注册界面到PageManager
 * @param page: Page对象
 */
void PageManager::pm_register(Page page) {
    pages[max_id ++] = page;
}

/**
 * @brief 通过PM注册界面
 * @param name: Page name
 * @param create_func: 创建回调函数
 * @param delete_func: 删除回调函数
 */
void PageManager::add_page(const char *name, lv_obj_t *(*create_func)(), lv_obj_t *(*delete_func)()) {
    Page page{};
    page.p_init(name, max_id, create_func, delete_func);
    pm_register(page);
}

/**
 * @brief 将指定页面推送到屏幕
 * @param name: 通过name查找Page
 * @param scrAnim: 屏幕切换动画
 */
void PageManager::push(const char *name, ScrAnim scrAnim) {
    if (current_page > 0) {
        pages[current_page].p_del();
    }
    lv_scr_load_anim(pages[get_id(name)].p_load(), scrAnim.anim_type, scrAnim.time, scrAnim.delay, true);
    current_page = get_id(name);
}

/**
 * @brief 将指定页面推送到屏幕（无动画）
 * @param name: 通过name查找Page
 */
void PageManager::push(const char *name) {
    if (current_page > 0) {
        pages[current_page].p_del();
    }
    lv_scr_load(pages[get_id(name)].p_load());
    current_page = get_id(name);
}
