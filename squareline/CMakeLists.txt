SET(SOURCES screens/ui_Screen1.c
    screens/ui_Screen2.c
    screens/ui_Screen3.c
    ui.c
    ui_helpers.c
    images/ui_img_wifi_closed_png.c
    images/ui_img_battery_png.c
    images/ui_img_link_png.c
    images/ui_img_time_png.c
    images/ui_img_follows_png.c
    images/ui_img_app_png.c
    images/ui_img_power_2_png.c)

add_library(ui ${SOURCES})
