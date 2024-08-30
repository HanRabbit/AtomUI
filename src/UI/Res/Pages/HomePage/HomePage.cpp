#include "HomePage.h"
#include "UI/Res/Components/StatusBar.h"

lv_obj_t *HomePage::create() {
    lv_obj_t *root = lv_obj_create(nullptr);

    StatusBar.create(root);

    return root;
}

lv_obj_t *HomePage::del() {
    return nullptr;
}
