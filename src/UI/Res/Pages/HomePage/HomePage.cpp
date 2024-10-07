#include "HomePage.h"
#include "view.h"
#include "Drivers/System/System.h"

lv_obj_t *HomePage::create() {
    lv_obj_t *root = lv_obj_create(nullptr);

    create_home_view(root);

    /* 系统启动结束，发布系统状态消息，进入主界面 */
    atom_system.launch_end();

    return root;
}

lv_obj_t *HomePage::del() {
    return nullptr;
}
