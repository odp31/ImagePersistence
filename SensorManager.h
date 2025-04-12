#ifndef SENSORMANAGER_H
#define SENSORMANGER_H


#include "config.h"

class SensorManager {
public:
  SensorManager(int hallPin, int irPin);
  void begin();
  bool isHallTriggered();
  bool isIRTriggered();

private:
  int hallPin;
  int irPin;
};

#endif

