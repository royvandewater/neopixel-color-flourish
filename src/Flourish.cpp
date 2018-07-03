#include "Flourish.h"
#include "Led.h"

Flourish::Flourish(uint8_t numLeds, uint8_t red, uint8_t green, uint8_t blue) {
  _numLeds = numLeds;
  _red = red;
  _green = green;
  _blue = blue;
}

bool Flourish::complete() {
  return false;
}

std::vector<Led> Flourish::render() {
  std::vector<Led> leds = std::vector<Led>();

  for (int i = 0; i < _numLeds; i++) {
    Led led = Led(i, 0, 0, 0);
    leds.push_back(led);
  }

  return leds;
}

void Flourish::tick() {
}
