#include "app.h"
#include "pages/pages.h"

PageManager pageManager;
MsgManager msgManager;

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
    pageManager.add_page("PAGE/SERIAL_MONITOR",
                         SerialMonitorPage::page_create,
                         SerialMonitorPage::page_delete);
    pageManager.add_page("PAGE/TRANSLATE",
                         TranslatePage::page_create,
                         TranslatePage::page_delete);
    pageManager.add_page("PAGE/OTAPage",
                         OTAPage::page_create,
                         OTAPage::page_delete);

    /* Start Push */
    pageManager.push("PAGE/STARTUP");
    lv_timer_create(go_into_home, 6200, nullptr);
}
