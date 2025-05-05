#include "TestPage.h"
#include "UI/Res/Components/StatusBar/StatusBar.h"
#include "UI/Utils/UIGroup/UIGroup.h"

lv_obj_t *TestPage::create() {
    lv_obj_t *root = lv_obj_create(nullptr);
    StatusBar.create(root);

    lv_obj_t *label = lv_label_create(root);
    lv_label_set_text(label, "TEST PAGE");
    lv_obj_set_align(label, LV_ALIGN_CENTER);

    lv_group_add_obj(group, StatusBar.back_button);

    return root;
}

lv_obj_t *TestPage::del() {
    return nullptr;
}
