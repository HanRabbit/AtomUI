#include "MessageManager.h"

#include <utility>

Message_Manager MessageManager;

/**
 * @brief 发布消息
 * @param key 消息键
 * @param value 消息值
 */
void Message_Manager::publish(String key, String value) {
    if (message_map.find(key.c_str()) != message_map.end()) {
        message_map.erase(key.c_str());
    }
    message_map.insert(std::make_pair<string, string> (key.c_str(), value.c_str()));
}

/**
 * @brief 通过 Key 获取消息
 * @param key 消息键
 * @return Value 消息值
 */
String Message_Manager::get(String key) {
    iterator = message_map.find(key.c_str());

    if (iterator != message_map.end())
        return iterator->second.c_str();
    else
        return "";
}

/**
 * @brief 订阅消息
 * @param key 消息键
 * @param msg_callback 消息更新回调函数
 */
void Message_Manager::subscribe(String key, void (*cb) (String)) {
//    message_t mt = {key, cb};
//
//    TimerManager.t_register([] (lv_timer_t *timer) {
//        auto *mt = static_cast<message_t *>(timer->user_data);
//        mt->cb(MessageManager.get(mt->key.c_str()));
//    }, MESSAGE_CALLBACK_DURATION, key.c_str(), &mt, false);
}
