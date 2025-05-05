#include "HomeApps.h"
#include "UI/Res/Components/SideBar/SideBar.h"

Home_Apps HomeApps;


/**
 * @brief 初始化 HomeApps，创建对应 Side Bar 图标
 */
void Home_Apps::init(lv_obj_t *root) {
    SideBar.init(root);
}


/**
 * @brief 注册 HomeApp
 * @param name 应用名称
 * @param page_name 应用页面名称
 * @param icon_path 应用图标路径
 */
void Home_Apps::register_app(const char *name, const char *page_name, const char *icon_path){
    Home_App home_app {};
    home_app.id = current_apps_num ++;
    home_app.name = name;
    home_app.page_name = page_name;
    home_app.icon_path = icon_path;

    home_app_list.push_back(home_app);

    /* 添加 Side Bar 按钮 */
    SideBar.add_button(name, page_name, icon_path);
}

