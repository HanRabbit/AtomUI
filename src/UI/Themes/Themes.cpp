#include "Themes.h"

/**
  * @brief  为对象添加动画
  * @param  obj:对象地址
  * @param  a:动画控制器地址
  * @param  exec_cb:控制对象属性的函数地址
  * @param  start:动画的开始值
  * @param  end:动画的结束值
  * @param  time:动画的执行时间
  * @param  ready_cb:动画结束事件回调
  * @param  path_cb:动画曲线
  * @retval 无
 */
void lv_obj_add_anim(
        lv_obj_t * obj, lv_anim_t * a,
        lv_anim_exec_xcb_t exec_cb,
        int32_t start, int32_t end,
        uint16_t time,
        lv_anim_ready_cb_t ready_cb,
        lv_anim_path_cb_t path_cb
) {
    lv_anim_t a_tmp;
    if(a == nullptr) {
        lv_anim_init(&a_tmp);
        a = &a_tmp;
    }

    a->var = obj;
    a->start_value = start;
    a->end_value = end;
    a->exec_cb = exec_cb;
    a->path_cb = path_cb;
    a->duration = time;
    lv_anim_start(a);
}
