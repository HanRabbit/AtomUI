#include "HomeApps.h"
#include "UI/Utils/PageManager/PageManager.h"

Home_Apps HomeApps;

/**
 * @brief 注册应用
 * @param name 应用名称
 * @param page_name 应用对应页面名称
 * @param icon_path 应用 Side Bar 图标路径
 */
void Home_Apps::register_app(const char *name, const char *page_name, const char *icon_path) {
    HomeApp app;
    app.name = name;
    app.icon_path = icon_path;
    app.page_name = page_name;
    /* 分配APP ID */
    app.id = registered_app_num;

    registered_app_num ++;

    /* 在应用列表中注册应用 */
    apps_list.push_back(app);
}

/**
 * @brief 通过应用名称查找应用
 * @param name 应用名称
 * @return 应用
 */
HomeApp Home_Apps::find(const char *name) {
    for (auto &app: apps_list) {
        if (strcmp(app.name, name) != 0) {
            return app;
        }
    }
//    return nullptr;
}

/**
 * @brief 推送应用页面
 * @param app HomeApp
 */
void Home_Apps::push_app_page(HomeApp app) {
    PageManager.p_push(app.page_name);
}

/**
 * @brief 创建应用侧边栏
 * @param app 应用实例
 * @param root 侧边栏视图根对象
 * @return 侧边栏对象
 */
void Home_Apps::create_app_side_bar(HomeApp app, lv_obj_t *root) {
    lv_obj_t *side_bar = lv_obj_create(root);
    /* 创建应用图标 */
    lv_obj_t *app_icon = lv_image_create(side_bar);

    lv_image_set_src(app_icon, app.icon_path);
}