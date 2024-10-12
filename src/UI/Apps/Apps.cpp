#include "Apps.h"

void HomeApps::init() {
    PageManager.init();

    /* App 注册入口 */
    PageManager.p_register("SYSTEM/LAUNCH", LaunchPage::create, LaunchPage::del);
    PageManager.p_register("SYSTEM/LOADING", LoadingPage::create, LoadingPage::del);
    PageManager.p_register("SYSTEM/HOME", HomePage::create, HomePage::del);
}

void HomeApps::launch() {
    PageManager.p_push("SYSTEM/LAUNCH");
}
