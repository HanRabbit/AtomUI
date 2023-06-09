#include "app.h"
#include "pages/startup/startup.h"
#include "pages/error/error.h"
#include "pages/home/home.h"

PageManager pageManager;

void go_into_home(lv_timer_t *timer) {
    pageManager.push("PAGE/HOME");
    
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

    /* Start Push */
    pageManager.push("PAGE/STARTUP");
    lv_timer_create(go_into_home, 6000, nullptr);
}
