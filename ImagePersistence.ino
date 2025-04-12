#include "NeoPixelController.h"
#include "SensorManager.h"
#include "ImageManager.h"
#include "config.h"


NeoPixelController neoPixel(NEOPIXEL_PIN, NUM_PIXELS);
SensorManager sensor(HALL_SENSOR_PIN, IR_SENSOR_PIN);
ImageManager image(IMAGE_WIDTH, IMAGE_HEIGHT);

// example image data (replace with your actual image)
uint32_t testImage[IMAGE_WIDTH * IMAGE_HEIGHT] = {
  0xFF0000, 0x00FF00, 0x0000FF, 
  0x0000FF, 0x00FF00, 0xFF0000, 
};

void setup() {
  neoPixel.begin();
  sensor.begin();
  image.setImageData(testImage);
}

void loop() {
  if(sensor.isHallTriggered()) {
    displayImage();
  }
  delay(ROTATION_INTERVAL);   //adjust for rotation speed
}

void displayImage() {
  for(int y = 0; y < IMAGE_HEIGHT; y++) {
    for(int x = 0; x < IMAGE_WIDTH; x++) {
      int pixelIndex = (y * IMAGE_WIDTH) + x;
      if(pixelIndex < NUM_PXIELS) {
        neoPixel.setPixelColor(pixelIndex, image.getPixelColor(x, y));
      }
    }
  }
  neoPixel.show();
  neoPixel.cleaar();
}
