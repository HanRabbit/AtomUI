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
        for (auto sub_cb: sub_cb_list) {
            sub_cb(content);
        }
    }
}

/**
 * @brief 消息订阅
 * @param id 消息 ID
 * @param sub_cb 消息订阅回调函数
 */
void Subscriber::subcribe(const String &id, function<void(String)> sub_cb) {
    auto iterator = MessagePool.pub_msg_buf.find(id.c_str());
    MessagePool.sub_msg_buf[id.c_str()].push_back(sub_cb);

    /* 如果已经发布过消息了，那么直接调用回调函数 */
    if (iterator != MessagePool.pub_msg_buf.end()) {
        sub_cb(iterator->second.c_str());
    }
}