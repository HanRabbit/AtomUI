#include "serial_monitor.h"
#include "ui/components/status_bar/status_bar.h"

extern StatusBar statusBar;
extern lv_group_t *ui_group;

lv_timer_t *serial_update_timer;
lv_obj_t *serial_text;
String serial_data_str = "";

void lv_serial_monitor_set_theme() {
    lv_disp_t * disp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_NONE), lv_palette_main(LV_PALETTE_BLUE),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(disp, theme);
}

void update_status(lv_timer_t *timer) {
    statusBar.status.title = "SERIAL MONITOR";
    statusBar.update();
}

void update_serial(lv_timer_t *timer) {
    if (LOG_.available()) {
        serial_data_str += "#646464 [" + String(millis() / 1000) + " s]: #" + Log::read() + "\n";
//        serial_data_str += "[" + String(millis() / 1000) + " s]: " + Log::read() + "\n";
        lv_label_set_text(serial_text, serial_data_str.c_str());
    }
}

lv_obj_t *SerialMonitorPage::page_create() {
    lv_obj_t *page_startup_scr = lv_obj_create(nullptr);
    lv_obj_set_style_bg_color(page_startup_scr, lv_color_hex(0x000000), LV_PART_MAIN);

    statusBar.margin_y = 0;
    statusBar.create_status_bar(page_startup_scr);

    serial_text = lv_label_create(page_startup_scr);
    lv_obj_set_size(serial_text, 290, 180);
    lv_label_set_text(serial_text, "");
    lv_obj_set_style_border_width(serial_text, 2, LV_PART_MAIN);
    lv_obj_set_style_border_color(serial_text, lv_color_hex(0x282828), LV_PART_MAIN);
    lv_obj_set_style_radius(serial_text, 2, LV_PART_MAIN);
    lv_label_set_recolor(serial_text, true);
    lv_obj_set_style_text_font(serial_text, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_align(serial_text, LV_ALIGN_CENTER, 0, 10);
    lv_obj_set_style_bg_color(serial_text, lv_color_hex(0x000000), LV_PART_MAIN);

    /* 初始化计时器 */
    statusBar.status_bar_timer = lv_timer_create(update_status, STATUS_BAR_UPDATE_DURING, nullptr);
    serial_update_timer = lv_timer_create(update_serial, SERIAL_READ_FREQUENT, nullptr);

    lv_group_remove_all_objs(ui_group);
    lv_group_add_obj(ui_group, serial_text);
    lv_group_focus_obj(serial_text);

    lv_serial_monitor_set_theme();

    return page_startup_scr;
}

lv_obj_t *SerialMonitorPage::page_delete() {
    return nullptr;
}
