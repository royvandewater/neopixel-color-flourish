#ifndef Flourish_h
#define Flourish_h

#include <vector>
#include <stdint.h>
#include "Led.h"

class Flourish {
public:
  Flourish(uint8_t numLeds, uint8_t red, uint8_t green, uint8_t blue);
  bool complete();
  std::vector<Led> render();
  void tick();
private:
  uint8_t _numLeds;
  uint8_t _red;
  uint8_t _green;
  uint8_t _blue;
};

#endif
