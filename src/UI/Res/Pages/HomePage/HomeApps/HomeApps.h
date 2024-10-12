#ifndef ATOM_UI_LV9_HOME_APPS_H
#define ATOM_UI_LV9_HOME_APPS_H

#include <Arduino.h>
#include <lvgl.h>
#include <vector>

using namespace std;

/* 主页应用结构体 */
typedef struct {
    const char *name;               /* 应用名称 */
    const char *page_name;          /* Side Bar 点击跳转页面名称 */
    const char *icon_path;          /* 应用图标路径 */
    uint16_t id;                    /* 应用 ID */
} HomeApp;

class Home_Apps {
public:
    uint16_t registered_app_num = 0;        /* 已注册过的应用数量 */
    vector<HomeApp> apps_list {};           /* APPS 池 */

    /* 注册应用 */
    void register_app(const char *name, const char *page_name, const char *icon_path);

    /* 应用跳转 */
    static void push_app_page(HomeApp app);

    /* 查找应用 */
    HomeApp find(const char *name);

    /* 创建应用侧边栏 */
    void create_app_side_bar(HomeApp app, lv_obj_t *root);
};

extern Home_Apps HomeApps;

#endif // ATOM_UI_LV9_HOME_APPS_H
