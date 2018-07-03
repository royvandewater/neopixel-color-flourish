#include "Flourish.h"

Flourish::Flourish(uint8_t numLEDs, uint8_t red, uint8_t green, uint8_t blue) {
  _numLEDs = numLEDs;
  _red = red;
  _green = green;
  _blue = blue;
}

bool Flourish::complete() {
  return false;
}
