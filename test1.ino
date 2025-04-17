#include <Adafruit_NeoPixel.h>

// Define the pin connected to the NeoPixel data line
#define PIN 3

// Define the number of NeoPixels in the strip
#define NUMPIXELS 8

// Create NeoPixel object
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Initialize the NeoPixel library
  pixels.begin();

  // Set the brightness (0-255)
  pixels.setBrightness(50); // Adjust as needed

  // Clear all pixels initially
  pixels.clear();
  pixels.show(); // Send the pixel data to the strip
}

void loop() {
  // --- Option 1: Light up all 8 LEDs with the same color ---
  uint32_t color = pixels.Color(255, 0, 0); // Red color (R, G, B)

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, color);
  }
  pixels.show(); // Update the NeoPixel strip

  delay(1000); // Keep the lights on for 1 second

  // Turn off all lights
  pixels.clear();
  pixels.show();
  delay(500); // Wait for 0.5 seconds

  // --- Option 2: Light up each LED with a different color ---
  for (int i = 0; i < NUMPIXELS; i++) {
    // Generate different colors (you can customize this)
    uint32_t individualColor = pixels.Color(random(0, 256), random(0, 256), random(0, 256));
    pixels.setPixelColor(i, individualColor);
  }
  pixels.show();
  delay(1000);

  // Turn off all lights
  pixels.clear();
  pixels.show();
  delay(500);
}
