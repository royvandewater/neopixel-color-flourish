#ifndef Flourish_h
#define Flourish_h

#include <vector>
#include <stdint.h>
#include "Animation.h"
#include "Led.h"

class Flourish: public Animation {
public:
  Flourish();
  Flourish(uint8_t numLeds, uint8_t red, uint8_t green, uint8_t blue);
  bool complete();
  std::vector<Led> render();
  void tick();
private:
  uint8_t _numLeds;
  uint8_t _red;
  uint8_t _green;
  uint8_t _blue;
  uint32_t _currentFrameNumber;

  Led _renderLed(uint32_t ledNumber);
  uint8_t _colorComponent(uint8_t color);
};

#endif
