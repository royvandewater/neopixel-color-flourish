#ifndef Pulse_h
#define Pulse_h

#include <stdint.h>
#include <vector>
#include "Animation.h"
#include "Led.h"

class Pulse: public Animation {
public:
  Pulse();
  Pulse(uint8_t numLeds, uint8_t red, uint8_t green, uint8_t blue);
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
  float _percent();
  uint8_t _step();
};

#endif
