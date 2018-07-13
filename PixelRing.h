#ifdef __AVR__
  #include <avr/power.h>
#endif

#ifndef PixelRing_h
#define PixelRing_h

#include <Adafruit_NeoPixel.h>
#include "Arduino.h"
#include "Animation.h"
#include "Flourish.h"
#include "Pulse.h"

class PixelRing {
public:
  PixelRing(uint8_t pin, uint8_t numberOfLEDs);
  bool animationComplete();
  void begin();
  void flourish(uint8_t red, uint8_t green, uint8_t blue);
  void pulse(uint8_t red, uint8_t green, uint8_t blue);
  void render();

private:
  int _pin;
  int _numberOfLEDs;
  uint32_t _currentColor;
  Adafruit_NeoPixel _ring;
  Animation* _animation;
  Flourish _flourish;
  Pulse _pulse;

  void setAnimation(Animation* _animation);
};

#endif
