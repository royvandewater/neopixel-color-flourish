#include "PixelRing.h"

#include "Arduino.h"
#include "Flourish.h"
#include "Led.h"
#include "Pulse.h"

PixelRing::PixelRing(uint8_t pin, uint8_t numberOfLEDs) {
  _ring = Adafruit_NeoPixel(numberOfLEDs, pin, NEO_GRB + NEO_KHZ800);
  _numberOfLEDs = numberOfLEDs;
  _flourish = Flourish(numberOfLEDs, 0, 0, 0);
  _pulse = Pulse(numberOfLEDs, 0, 0, 0);
  _animation = &_flourish;
  _red = 0;
  _green = 0;
  _blue = 0;
}

bool PixelRing::animationComplete() {
  return _animation->complete();
}

void PixelRing::begin() {
  _ring.begin();
  _ring.setBrightness(255);
  _ring.show();
}

void PixelRing::flourish() {
  _flourish = Flourish(_numberOfLEDs, _red, _green, _blue);
  _animation = &_flourish;
}

void PixelRing::pulse() {
  _pulse = Pulse(_numberOfLEDs, _red, _green, _blue);
  _animation = &_pulse;
}

void PixelRing::render() {
  std::vector<Led> leds = _animation->render();

  for (int i=0; i<leds.size(); i++) {
    Led led = leds[i];
    _ring.setPixelColor(led.ledNumber, _ring.Color(led.red, led.green, led.blue));
  }
  _ring.show();

  _animation->tick(); // advance the flourish
}

void PixelRing::setColor(uint8_t red, uint8_t green, uint8_t blue) {
  _red = red;
  _green = green;
  _blue = blue;
}
