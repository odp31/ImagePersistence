# Image Persistence Display

This project demonstrates the phenomenon of image persistence using a rotating NeoPixel strip controlled by an Arduino Nano. By rapidly displaying slices of an image, the human eye perceives a complete, stable image due to the persistence of vision.

## Components

* Arduino Nano
* NeoPixel LED strip (addressable)
* Hall effect sensor (for rotation detection)
* IR sensor (optional, for additional control)
* 3.7V LiPo battery
* 3D-printed mount/casing
* Wiring and connectors

## Project Structure

ImagePersistence/
├── ImagePersistence.ino
├── NeoPixelController.cpp
├── NeoPixelController.h
├── SensorManager.cpp
├── SensorManager.h
├── ImageManager.cpp
├── ImageManager.h
└── config.h


* `ImagePersistence.ino`: Main Arduino sketch.
* `NeoPixelController.cpp/h`: Handles NeoPixel strip control.
* `SensorManager.cpp/h`: Manages sensor input (Hall effect, IR).
* `ImageManager.cpp/h`: Manages image data.
* `config.h`: Configuration settings (pins, image dimensions).

## Hardware Setup

1.  **Wiring:**
    * Connect the NeoPixel data line to the specified Arduino pin (defined in `config.h`).
    * Connect the Hall effect sensor and IR sensor (if used) to their respective Arduino pins.
    * Connect the LiPo battery to the Arduino's power input.
    * Ensure proper grounding for all components.
2.  **Mounting:**
    * Use the 3D-printed mount to securely hold the Arduino, sensors, and NeoPixel strip.
    * The mount should allow for smooth rotation of the NeoPixel strip.
3.  **Power:**
    * Verify that the LiPo battery can provide sufficient current for the NeoPixel strip.
    * It is very important to add a large capacitor across the power supply of the neopixel strip.

## Software Setup

1.  **Arduino IDE:**
    * Install the Arduino IDE.
    * Install the Adafruit NeoPixel library through the Library Manager.
2.  **Code Upload:**
    * Open `ImagePersistence.ino` in the Arduino IDE.
    * Modify `config.h` to match your hardware setup (pin numbers, NeoPixel length, image dimensions).
    * Replace the example image data in `ImagePersistence.ino` with your desired image.
    * Select the correct Arduino board and port.
    * Upload the code to the Arduino Nano.

## Usage

1.  Power on the Arduino.
2.  Rotate the NeoPixel strip.
3.  The Hall effect sensor will trigger the image display, and the persistence of vision will create a stable image.
4.  (Optional) The IR sensor can be used for additional control or triggering.
5.  Adjust the `ROTATION_INTERVAL` in `config.h` to fine-tune the image display.

## Configuration

* **`config.h`:**
    * `HALL_SENSOR_PIN`: Arduino pin connected to the Hall effect sensor.
    * `IR_SENSOR_PIN`: Arduino pin connected to the IR sensor.
    * `NEOPIXEL_PIN`: Arduino pin connected to the NeoPixel data line.
    * `NUM_PIXELS`: Number of LEDs in the NeoPixel strip.
    * `IMAGE_WIDTH`: Width of the image in pixels.
    * `IMAGE_HEIGHT`: Height of the image in pixels.
    * `ROTATION_INTERVAL`: Time interval (milliseconds) between image slices, controlling rotation speed.

## Image Data

* The image data is stored as an array of `uint32_t` values, where each value represents an RGB color.
* Replace the example image data in `ImagePersistence.ino` with your own image data.
* Ensure the image dimensions match the `IMAGE_WIDTH` and `IMAGE_HEIGHT` defined in `config.h`.

## Notes

* Adjust sensor logic (HIGH/LOW triggers) based on your sensor's output.
* Fine-tune the `ROTATION_INTERVAL` for optimal image persistence.
* Ensure adequate power supply for the NeoPixel strip.
* Properly secure all wiring and components.
* Be carefull with the LiPo battery.

## Credits

* Adafruit NeoPixel library: [https://github.com/adafruit/Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel)

Enjoy your image persistence display!
