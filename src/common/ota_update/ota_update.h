#ifndef ATOM_UI_OTA_UPDATE_H
#define ATOM_UI_OTA_UPDATE_H

#include <Arduino.h>
#include <HTTPUpdate.h>
#include "common/log/log.h"

#define OTA_UPDATE_URL "http://bin.bemfa.com/b/3BcMGYwYzRmM2UwNTBmNDZkNDlkNTBlODRhZjhkNTE1N2I=AtomUI.bin"

t_httpUpdate_return OTA_update();

#endif //ATOM_UI_OTA_UPDATE_H
