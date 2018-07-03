#include "Led.h"

Led::Led(uint8_t _ledNumber, uint8_t _red, uint8_t _green, uint8_t _blue) {
  ledNumber = _ledNumber;
  red = _red;
  green = _green;
  blue = _blue;
}

bool operator==(Led left, Led right) {
  return left.ledNumber == right.ledNumber \
  && left.red == right.red \
  && left.green == right.green \
  && left.blue == right.blue;
}
