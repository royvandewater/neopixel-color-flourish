#ifndef Flourish_h
#define Flourish_h

#include <list>
#include <stdint.h>

struct Frame {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

class Flourish {
public:
  Flourish(uint8_t numLEDs, uint8_t red, uint8_t green, uint8_t blue);
  bool complete();
  std::list<Frame> render();
private:
  uint8_t _numLEDs;
  uint8_t _red;
  uint8_t _green;
  uint8_t _blue;
};

#endif
