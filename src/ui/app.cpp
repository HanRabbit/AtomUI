#include "app.h"
#include "pages/startup/startup.h"
#include "pages/error/error.h"
#include "pages/home/home.h"
//#include "pages/_test/_test.h"

PageManager pageManager;

void go_into_home(lv_timer_t *timer) {
    if (sys_indev_check() == SYS_SELF_CHECK_OK) {
        pageManager.push("PAGE/HOME", PM_SCR_ANIM_OVER_TOP);
    } else {
        pageManager.push("PAGE/ERROR", PM_SCR_ANIM_FADE_ON);
    }

    lv_timer_del(timer);
}

void app_init() {
    pageManager.add_page("PAGE/STARTUP",
             StartupPage::page_create,
             StartupPage::page_delete);
    pageManager.add_page("PAGE/ERROR",
                         ErrorPage::page_create,
                         ErrorPage::page_delete);
    pageManager.add_page("PAGE/HOME",
                         HomePage::page_create,
                         HomePage::page_delete);
//
//    pageManager.add_page("PAGE/TEST",
//                         TestPage::page_create,
//                         TestPage::page_delete);

    pageManager.push("PAGE/STARTUP");
    lv_timer_create(go_into_home, 4000, nullptr);
}
