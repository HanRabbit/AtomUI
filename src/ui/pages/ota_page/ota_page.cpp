#include "ota_page.h"
#include "ui/res/rp/rp.h"

lv_obj_t *tips_label;

void set_update_tips(const char *tips) {
    lv_label_set_text(tips_label, tips);
}

void update_timer_cb(lv_timer_t *timer) {
    switch (OTA_update()) {
        case HTTP_UPDATE_NO_UPDATES:
            set_update_tips("No updates");
            break;
        case HTTP_UPDATE_FAILED:
            set_update_tips("Update failed");
            break;
        case HTTP_UPDATE_OK:
            set_update_tips("Update succeed");
//            lv_timer_create(reboot_timer_cb, 200000, nullptr);
            break;
    }
//    ESP.restart();
    lv_timer_del(timer);
}

void update_ota_status(int cur, int total) {
    set_update_tips(("CALLBACK:  HTTP update process at " + String(cur) +" of " + String(total) + " bytes...").c_str());
    Log::msg("TOA Update", "CALLBACK:  HTTP update process at " + String(cur) +" of " + String(total) + " bytes...");
    lv_timer_handler();
}

void OTAPage::ui_event(lv_event_t *e) {
    lv_event_code_t e_code = lv_event_get_code(e);

    lv_timer_create(update_timer_cb, 1000, nullptr);

    httpUpdate.onProgress(update_ota_status);
}

lv_obj_t *OTAPage::page_create() {
    lv_obj_t *scr = lv_obj_create(nullptr);
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_add_event_cb(scr, ui_event, LV_EVENT_SCREEN_LOADED, nullptr);

    lv_obj_t *ui_gif_update_obj = lv_gif_create(scr);
    lv_gif_set_src(ui_gif_update_obj, &ui_gif_update);
    lv_obj_set_width(ui_gif_update_obj, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_gif_update_obj, LV_SIZE_CONTENT);
    lv_obj_align(ui_gif_update_obj, LV_ALIGN_CENTER, 0, 0);

    tips_label = lv_label_create(scr);
    set_update_tips("Checking update");
    lv_obj_align(tips_label, LV_ALIGN_CENTER, 0, 60);

    return scr;
}

lv_obj_t *OTAPage::page_delete() {
    return nullptr;
}
