#include "Apps.h"

#include "Common/MessageManager/MessageManager.h"

void Apps::init() {
    PageManager.init();

    /* App 注册入口 */
    PageManager.p_register("SYSTEM/LAUNCH", LaunchPage::create, LaunchPage::del);
    PageManager.p_register("SYSTEM/LOADING", LoadingPage::create, LoadingPage::del);
    PageManager.p_register("SYSTEM/HOME", HomePage::create, HomePage::del);

    lv_timer_create([] (lv_timer_t * timer) {
        MessageManager.publish("COMP/MESSAGE", String(millis()));
    }, 1000, nullptr);

    lv_timer_create([] (lv_timer_t * timer) {
        USBSerial.println(MessageManager.get("COMP/MESSAGE"));
    }, 1000, nullptr);
}

void Apps::play_start_anim() {
    PageManager.p_push("SYSTEM/LAUNCH");
}
