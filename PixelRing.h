#ifdef __AVR__
  #include <avr/power.h>
#endif

#ifndef PixelRing_h
#define PixelRing_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class PixelRing {
public:
  PixelRing(int pin, int numberOfLEDs);
  bool animationComplete();
  void begin();
  void flourish(uint32_t color);
  void render();

  static uint32_t Color(uint8_t r, uint8_t g, uint8_t b);
  static uint32_t RandomColor();
private:
  int _pin;
  int _numberOfLEDs;
  uint32_t _currentColor;
  Adafruit_NeoPixel _ring;
};

#endif
