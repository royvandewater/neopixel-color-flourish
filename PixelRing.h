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
  void flourish();
  void pulse();
  void render();
  void setColor(uint8_t red, uint8_t green, uint8_t blue);

private:
  int _pin;
  int _numberOfLEDs;
  uint8_t _red;
  uint8_t _green;
  uint8_t _blue;
  Adafruit_NeoPixel _ring;
  Animation* _animation;
  Flourish _flourish;
  Pulse _pulse;

  void setAnimation(Animation* _animation);
};

#endif
