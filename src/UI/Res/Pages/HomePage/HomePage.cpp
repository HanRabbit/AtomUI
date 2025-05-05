#include "HomePage.h"
#include "view.h"
#include "Drivers/System/System.h"
#include "UI/Apps/HomeApps.h"
#include "UI/Res/ResourcePool/ResourcePool.h"
#include "Common/TimerManager/TimerManager.h"
#include "UI/Utils/PageManager/PageManager.h"
#include "Common/MessageManager/Account.h"

lv_obj_t *root;

lv_obj_t *HomePage::create() {
    root = lv_obj_create(nullptr);
    lv_obj_set_flex_flow(root, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(root, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    /* 创建主页视图 */
    create_home_view(root);
    HomeApps.init(root);

    /* 创建主页 APPS */
    HomeApps.register_app("TEST", "APP/TEST", COMP_WIFI_OPEN_IMG_PATH);
    HomeApps.register_app("TEST2", "APP/TEST", COMP_BACK_IMG_PATH);

    /* 系统启动结束，发布系统状态消息，进入主界面 */
    atom_system.launch_end();

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
