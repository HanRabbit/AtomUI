#include "app.h"
#include "pages/startup/startup.h"
#include "ui/pages/_template/_template.h"

PageManager pageManager;

void app_init() {
    StartupPage startupPage;
    TemplatePage _templatePage;

    pageManager.add_page("PAGE/STARTUP",
             startupPage.page_create,
             startupPage.page_delete);

    pageManager.add_page("PAGE/_TEMPLATE",
                         _templatePage.page_create,
                         _templatePage.page_delete);

    pageManager.push("PAGE/STARTUP");
}
