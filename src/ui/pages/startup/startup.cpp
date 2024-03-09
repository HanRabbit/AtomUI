#include "startup.h"
#include "ui/res/rp/rp.h"
#include "ui/utils/msg_manager/msg_manager.h"
#include "indev/io_map/io_map.h"

static lv_obj_t *ui_scr;
//static lv_obj_t *ui_label_atom;
static lv_obj_t *ui_gif_atom;
static lv_obj_t *ui_mask_panel;
static lv_obj_t *ui_bar;

extern MsgManager msgManager;

static void start_up_bar_cb(lv_timer_t *timer) {
    lv_bar_set_value(ui_bar, 100, LV_ANIM_ON);
    lv_timer_del(timer);
}

void StartupPage::ui_event(lv_event_t *e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if ( event_code == LV_EVENT_SCREEN_LOADED) {
        lv_timer_create(start_up_bar_cb, 400, nullptr);
        anim_fade_out(ui_bar, 5600);
    }
}

lv_obj_t *StartupPage::page_create() {
    ui_scr = lv_obj_create(nullptr);
    lv_obj_clear_flag(ui_scr, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_scr, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_gif_atom = lv_gif_create(ui_scr);
    lv_gif_set_src(ui_gif_atom, &ui_img_atom_gif);
    lv_obj_set_width(ui_gif_atom, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_gif_atom, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_gif_atom, LV_ALIGN_CENTER);

    digitalWrite(LED_PIN, LOW);

//    ui_label_atom = lv_label_create(ui_scr);
//    lv_obj_set_width( ui_label_atom, LV_SIZE_CONTENT);
//    lv_obj_set_height( ui_label_atom, LV_SIZE_CONTENT);
//    lv_obj_set_align( ui_label_atom, LV_ALIGN_CENTER );
//    lv_label_set_text(ui_label_atom,"ATOM");
//    lv_obj_set_style_text_color(ui_label_atom, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
//    lv_obj_set_style_text_opa(ui_label_atom, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
//    lv_obj_set_style_text_font(ui_label_atom, &lv_font_montserrat_32, LV_PART_MAIN| LV_STATE_DEFAULT);

//    ui_mask_panel = lv_obj_create(ui_scr);
//    lv_obj_set_width( ui_mask_panel, 120);
//    lv_obj_set_height( ui_mask_panel, 50);
//    lv_obj_set_x( ui_mask_panel, 0 );
//    lv_obj_set_y( ui_mask_panel, 46 );
//    lv_obj_set_align( ui_mask_panel, LV_ALIGN_CENTER );
//    lv_obj_clear_flag( ui_mask_panel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
//    lv_obj_set_style_radius(ui_mask_panel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
//    lv_obj_set_style_bg_color(ui_mask_panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
//    lv_obj_set_style_bg_opa(ui_mask_panel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
//    lv_obj_set_style_border_width(ui_mask_panel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

    ui_bar = lv_bar_create(ui_scr);
    lv_obj_set_style_anim_time(ui_bar, 2000, 0);
    lv_obj_set_width(ui_bar, 120);
    lv_obj_set_height(ui_bar, 3);
    lv_obj_set_x(ui_bar, 0);
    lv_obj_set_y(ui_bar, 22);
//    lv_obj_set_style_bg_color(ui_bar, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bar, lv_color_hex(0x000000), 0);
    lv_obj_set_align(ui_bar, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_scr, ui_event, LV_EVENT_ALL, nullptr);

    return ui_scr;
}

lv_obj_t *StartupPage::page_delete() {
    return nullptr;
}