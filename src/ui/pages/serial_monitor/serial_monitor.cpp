#include "serial_monitor.h"
#include "ui/components/status_bar/status_bar.h"

extern StatusBar statusBar;

lv_obj_t *SerialMonitorPage::page_create() {
    lv_obj_t *page_startup_scr = lv_obj_create(nullptr);
    lv_obj_set_style_bg_color(page_startup_scr, lv_color_hex(0x000000), LV_PART_MAIN);

    statusBar.margin_y = 0;
    statusBar.create_status_bar(page_startup_scr);
    statusBar.set_title("SERIAL MONITOR");

    lv_obj_t *serial_textarea = lv_textarea_create(page_startup_scr);
    lv_obj_set_size(serial_textarea, 290, 180);
    lv_textarea_set_placeholder_text(serial_textarea, "");
    lv_obj_align(serial_textarea, LV_ALIGN_CENTER, 0, 10);
    lv_obj_set_style_bg_color(serial_textarea, lv_color_hex(0x000000), LV_PART_MAIN);

    return page_startup_scr;
}

lv_obj_t *SerialMonitorPage::page_delete() {
    return nullptr;
}
