#ifndef Led_h
#define Led_h

#include <stdint.h>

struct Led {
public:
  uint8_t frameNumber;
  uint8_t red;
  uint8_t green;
  uint8_t blue;

  Led(uint8_t frameNumber, uint8_t red, uint8_t green, uint8_t blue);
};

bool operator==(Led left, Led right);

#endif
