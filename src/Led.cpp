#include "Led.h"

Led::Led(uint8_t _frameNumber, uint8_t _red, uint8_t _green, uint8_t _blue) {
  frameNumber = _frameNumber;
  red = _red;
  green = _green;
  blue = _blue;
}

bool operator==(Led left, Led right) {
  return left.frameNumber == right.frameNumber \
  && left.red == right.red \
  && left.green == right.green \
  && left.blue == right.blue;
}
