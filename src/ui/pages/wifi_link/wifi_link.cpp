#include "wifi_link.h"
#include "wifi_config_view.h"
#include "ui/res/rp/rp.h"
#include "ui/components/status_bar/status_bar.h"

extern StatusBar statusBar;
extern lv_group_t *ui_group;

void update_status_wifi_config(lv_timer_t *timer) {
    statusBar.status.title = "WiFi CONFIG";
    statusBar.update();
}

lv_obj_t *WiFiLinkPage::page_create() {
    lv_obj_t *scr = lv_obj_create(nullptr);

    lv_group_remove_all_objs(ui_group);

    create_wifi_guide(scr);

    statusBar.margin_y = 0;
    statusBar.create_status_bar(scr);

    /* 初始化计时器 */
    statusBar.status_bar_timer = lv_timer_create(update_status_wifi_config, STATUS_BAR_UPDATE_DURING, nullptr);
    lv_group_add_obj(ui_group, statusBar.ui_back_button);

    return scr;
}

lv_obj_t *WiFiLinkPage::page_delete() {
    return nullptr;
}
