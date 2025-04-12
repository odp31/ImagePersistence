// stores configuration constants (pin numbers, image dimensions, etc.)

#ifndef CONFIG_H
#define CONFIG_H

// Pin Definitions
const int HALL_SENSOR_PIN = 2;   // example pin
const int IR_SENSOR_PIN = 3;    // example pin
const int NEOPIXEL_PIN = 6;    // example pin

// NeoPixel Configuration
const int NUM_PIXELS = 144;   // adjust based on strip length
const int IMAGE_WIDTH = 12;    // example image width
const int IMAGE_HEIGHT = 12;     // example image height 

// Rotation Speed Settings
const unsigned long ROTATION_INTERVAL = 10;   // milliseconds, adjust as needed

#endif
