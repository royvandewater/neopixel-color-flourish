#include "Arduino.h"
#include "PixelRing.h"

PixelRing::PixelRing(int pin, int numberOfLEDs) {
  _ring = Adafruit_NeoPixel(numberOfLEDs, pin, NEO_GRB + NEO_KHZ800);
  _numberOfLEDs = numberOfLEDs;
  _currentColor = PixelRing::Color(64, 64, 0);
}

bool PixelRing::animationComplete() {
  return true;
}

void PixelRing::begin() {
  _ring.begin();
}

void PixelRing::flourish(uint32_t color) {
  _ring.setBrightness(255);

  for(uint16_t i=0; i<_ring.numPixels(); i++) {
    _ring.setPixelColor(i, color);
    _ring.show();
    delay(50);
  }
}

void PixelRing::render() {
  _ring.show(); // Initialize all pixels to 'off'
}

uint32_t PixelRing::Color(uint8_t r, uint8_t g, uint8_t b) {
  return Adafruit_NeoPixel::Color(r, g, b);
}

uint32_t PixelRing::RandomColor() {
  uint8_t r = rand() % 255;
  uint8_t g = rand() % 255;
  uint8_t b = rand() % 255;
  return PixelRing::Color(r, g, b);
}
