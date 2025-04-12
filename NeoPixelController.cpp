#include "NeoPixelController.h"

NeoPixelController::NeoPixelController(int pin, int numPixels) : strip(numPixels, pin, NEO_GRB + NEO_KHZ800) {}

void NeoPixelController::begin() {
  strip.begin();
  strip.show();
}

void NeoPixelController::setPixelColor(int pixel, uint32_t color) {
  strip.setPixelColor(pixel, color);
}

void NeoPixelController::show() {
  strip.show();
}

void NeoPixelController::clear() {
  strip.clear();
  strip.show();
}

