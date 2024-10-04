#include "HomePage.h"
#include "Common/MessageManager/Publisher.h"
#include "Common/MessageManager/Subscriber.h"
#include "view.h"

lv_obj_t *ui_root_panel, *ui_menu_panel;
lv_obj_t *ui_side_bar_panel;
lv_obj_t *ui_hour_min_label;

lv_obj_t *HomePage::create() {
    lv_obj_t *root = lv_obj_create(nullptr);

    create_home_view(root);

//    lv_timer_create([] (lv_timer_t *timer) {
//        if (WiFi_Op.is_connected()) {
//            Time.init();
//        }
//        lv_label_set_text(ui_hour_min_label, Time.get_time_str(false).c_str());
//    }, HOME_PAGE_UPDATE_DURATION, nullptr);

    return root;
}

lv_obj_t *HomePage::del() {
    return nullptr;
}
