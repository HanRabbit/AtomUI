#include "Account.h"

Publisher publisher;
Subscriber subscriber;

/**
 * @brief 消息发布
 * @param id 消息 ID
 * @param content 消息内容
 */
void Publisher::publish(const String &id, const String &content) {
    MessagePool.pub_msg_buf[id.c_str()] = content.c_str();

    if (!MessagePool.sub_msg_buf.empty()) {
        auto sub_cb_list = MessagePool.sub_msg_buf.find(id.c_str())->second;

        /* 执行所有订阅的回调函数 */
        for (const auto& sub_cb: sub_cb_list) {
            sub_cb.sub_cb(content);
        }
    }
}

/**
 * @brief 消息订阅
 * @param id 消息 ID
 * @param sub_cb 消息订阅回调函数
 */
void Subscriber::subscribe(const String &id, const SubscriberFunc& subscriber_func) {
    auto iterator = MessagePool.pub_msg_buf.find(id.c_str());
    MessagePool.sub_msg_buf[id.c_str()].push_back(subscriber_func);

    /* 如果已经发布过消息了，那么直接调用回调函数 */
    if (iterator != MessagePool.pub_msg_buf.end()) {
        subscriber_func.sub_cb(iterator->second.c_str());
    }
}

/**
 * @brief 清空消息订阅
 * @param id 消息 ID
 */
void Subscriber::subscribe_clear(const String &id) {
    MessagePool.sub_msg_buf[id.c_str()].clear();
}

/**
 * @brief 删除指定消息订阅
 * @param id 消息 ID
 * @param sub_cb_name 订阅回调函数名称
 */
void unsubscribe(const String& id, const String& sub_cb_name) {
    auto subscriber_func_list = MessagePool.sub_msg_buf[id.c_str()];
    uint16_t sub_func_index = 0;
    for (auto &sub_func: subscriber_func_list) {
        if (sub_func.sub_cb_name == sub_cb_name)
            subscriber_func_list.erase(subscriber_func_list.begin() + sub_func_index);
        sub_func_index ++;
    }
}