#include "Apps.h"

void Apps::init() {
    PageManager.init();

    /* 系统 APP */
    PageManager.p_register("SYSTEM/LAUNCH", LaunchPage::create, LaunchPage::del);
    PageManager.p_register("SYSTEM/LOADING", LoadingPage::create, LoadingPage::del);
    PageManager.p_register("SYSTEM/HOME", HomePage::create, HomePage::del);

    /* App 注册入口 */
    PageManager.p_register("APP/TEST",TestPage::create, TestPage::del);
    PageManager.p_register("APP/FB_CONTROLLER", FBControllerPage::create, FBControllerPage::del);
}

/* 配置 ATOM 启动页面处理 */
void Apps::launch() {
    PageManager.p_push("SYSTEM/LAUNCH");
    // PageManager.p_push("SYSTEM/LOADING");
}
