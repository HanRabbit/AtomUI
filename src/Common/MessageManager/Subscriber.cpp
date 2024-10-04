#include "Subscriber.h"
#include "MessagePool.h"

Subscriber subscriber;

void Subscriber::subcribe(const String &id, function<void(String)> sub_cb) {
    MessagePool.sub_msg_buf[id.c_str()].push_back(sub_cb);
}
