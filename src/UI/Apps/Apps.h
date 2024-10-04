#ifndef ATOM_UI_LV9_APPS_H
#define ATOM_UI_LV9_APPS_H

#include <Arduino.h>
#include <lvgl.h>

#include "UI/Utils/PageManager/PageManager.h"
#include "UI/Themes/Themes.h"

#include "UI/Res/Pages/LaunchPage/LaunchPage.h"
#include "UI/Res/Pages/LoadingPage/LoadingPage.h"
#include "UI/Res/Pages/HomePage/HomePage.h"

class Apps {
public:
    void init();

    void launch();
};

#endif // ATOM_UI_LV9_APPS_H
