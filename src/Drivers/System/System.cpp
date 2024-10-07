#include "System.h"
#include "Common/MessageManager/Account.h"

AtomSystem atom_system;

void AtomSystem::launch_begin() {
    start_time_stamp = (float) millis() / 1000;
}

void AtomSystem::launch_end() {
    start_duration = (float) ((float) millis() / 1000) - start_time_stamp;
    publisher.publish(MSG_ID_SYSTEM_START_DURATION, String(start_duration));
}
