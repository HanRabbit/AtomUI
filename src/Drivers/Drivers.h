#ifndef DRIVERS_H
#define DRIVERS_H

#include "Drivers/Display/Display.h"
#include "Common/Log/Log.h"
#include "Drivers/SD_Card/SD_Card.h"

class Drivers {
public:
  /* 外围器件初始化 */
  void init();
};

#endif //DRIVERS_H
