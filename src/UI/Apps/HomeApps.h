#ifndef HOME_APPS_H
#define HOME_APPS_H

#include <Arduino.h>
#include <vector>
#include <lvgl.h>

using namespace std;

/* 最大应用数量 */
#define HOME_APPS_NUM_MAX 64

class Home_App {
public:
    const char *name;           /* 应用名称 */
    const char *page_name;      /* 应用页面名称 */
    const char *icon_path;      /* 应用图标路径 */
    uint16_t id;                /* 应用唯一 ID */
};

class Home_Apps {
private:
    uint16_t current_apps_num = 0;

public:
    vector<Home_App> home_app_list;

    void register_app(const char *name, const char *page_name, const char *icon_path);

    void init(lv_obj_t *root);
};

extern Home_Apps HomeApps;

#endif //HOME_APPS_H
