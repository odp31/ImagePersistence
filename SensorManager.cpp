#include "SensorManager.h"

SensorManager::SensorManager(int hallPin, int irPin) : hallPin(hallPin), irPin(irPin) {}

void SensorManager::begin() {
  pinMode(hallPin, INPUT_PULLUP);   // Or INPUT, depending on sensor
  pinMode(irPin, INPUT);
}

bool SensorManager::isHallTriggered() {
  return digitalRead(hallPin) == LOW;    //adjust based on sensor output
}

bool SensorManager::isIRTriggered() {
  return digitalRead(irPin) == HIGH;     //adjust based on sensor output
}

