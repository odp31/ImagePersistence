#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include "config.h"

class ImageManager {
public:
  ImageManager(int width, int height);
  uint32_t getPixelColor(int x, int y);
  void setImageData(const uint32_t* data);

private:
  int width;
  int height;
  uint32_t* imageData;
};

#endif

