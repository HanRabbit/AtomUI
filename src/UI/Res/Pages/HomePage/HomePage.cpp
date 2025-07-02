#include "HomePage.h"
#include "view.h"
#include "UI/Apps/HomeApps.h"
#include "UI/Res/ResourcePool/ResourcePool.h"
#include "Common/TimerManager/TimerManager.h"
#include "Common/MessageManager/Account.h"

lv_obj_t *root;

lv_obj_t *HomePage::create() {
    root = lv_obj_create(nullptr);
    lv_obj_set_flex_flow(root, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(root, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    publisher.publish(MSG_ID_SYSTEM_APP_TITLE, "ATOM");

    /* 创建主页视图 */
    create_home_view(root);
    HomeApps.init(root);

    /* 创建主页 APPS */
    HomeApps.register_app("WIFI_CONFIG", "APP/WIFI_STATUS", COMP_WIFI_OPEN_IMG_PATH);
    HomeApps.register_app("FB_CONTROLLER", "APP/FB_CONTROLLER", HOME_APPS_IMG_PATH);

    return root;
}

lv_obj_t *HomePage::del() {
    /* 删除定时器，释放空间 */
    TimerManager.t_delete("TIMER/SIDE_BAR_RESET");

    /* 清除消息订阅 */
    subscriber.subscribe_clear(MSG_ID_SYSTEM_START_DURATION);
    subscriber.subscribe_clear(MSG_ID_SYSTEM_APP_NUM);
    subscriber.subscribe_clear(MSG_ID_TIME_HM);
    subscriber.subscribe_clear(MSG_ID_TIME_SEC);
    subscriber.subscribe_clear(MSG_ID_TIME_WDAY);
    subscriber.subscribe_clear(MSG_ID_TIME_DAY);

    /* 删除页面根组件，释放内存 */
    lv_obj_clean(root);

    return nullptr;
}
