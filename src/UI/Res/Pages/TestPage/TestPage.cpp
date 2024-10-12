#include "TestPage.h"

lv_obj_t *TestPage::create() {
    lv_obj_t *root = lv_obj_create(nullptr);

    lv_obj_t *label = lv_label_create(root);
    lv_label_set_text(label, "TEST PAGE");

    return root;
}

lv_obj_t *TestPage::del() {
    return nullptr;
}
