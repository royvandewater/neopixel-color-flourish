#ifndef Flourish_h
#define Flourish_h

#include <stdint.h>

class Flourish {
public:
  Flourish(uint32_t color);
  bool complete();
  //    void renderFrame();
private:
  uint32_t _color;
};

#endif
