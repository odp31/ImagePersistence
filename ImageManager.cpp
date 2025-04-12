#include "ImageManager.h"

ImageManager::ImageManager(int width, int height) : width(width), height(height) {
  imageData = new uint32_t[width * height];
}


uint32_t ImageManager::getPixelColor(int x, int y) {
  if(x >= 0 && x < width && y >= 0 && y < height) {
    return imageData[y * width + x];
  }
  return 0;
}

void ImageManager::setImageData(const uint32_t* data) {
  for(int i = 0; i < width * height; i++) {
    imageData[i] = data[i];
  }
}
