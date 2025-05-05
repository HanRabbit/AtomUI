#ifndef SIDE_BAR_H
#define SIDE_BAR_H

#include <lvgl.h>

#define SIDE_BAR_OUT_TIME 1
#define SIDE_BAR_BG_COLOR 0x0
#define SIDE_BAR_BUTTON_COLUMN 26

#define SIDE_BAR_BUTTON_COLLASPE_DURATION 2000

class Side_Bar {
public:
    bool side_bar_is_open = false;
    lv_obj_t *ui_side_bar {};

    void init(lv_obj_t *root);
    void add_button(const char *name, const char *page_name, const char *icon_path);
    lv_obj_t *get_side_bar_obj();
};

extern Side_Bar SideBar;

#endif //SIDE_BAR_H
