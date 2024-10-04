#include "Account.h"
#include "MessagePool.h"

Publisher publisher;
Subscriber subscriber;

void Publisher::publish(const String &id, const String &content) {
    MessagePool.pub_msg_buf[id.c_str()] = content.c_str();

    if (!MessagePool.sub_msg_buf.empty()) {
        auto sub_cb_list = MessagePool.sub_msg_buf.find(id.c_str())->second;
        for (auto sub_cb: sub_cb_list) {
            sub_cb(content);
        }
    }
}

void Subscriber::subcribe(const String &id, function<void(String)> sub_cb) {
    MessagePool.sub_msg_buf[id.c_str()].push_back(sub_cb);
}