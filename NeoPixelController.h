#ifndef NEOPIXELCONTROLLER_H
#define NEOPIXELCONTROLLER_H

#include <Adafruit_NeoPixel.h>
#include "config.H"

class NeoPixelController {
public:
  NeoPixelController(int pin, int numPixels);
  void begin();
  void setPixelColor(int pixel, uint32_t color);
  void show();
  void clear();

private:
  Adafruit_NeoPixel strip;
};

#endif
