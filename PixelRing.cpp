#include "PixelRing.h"

#include "Arduino.h"
#include "Flourish.h"
#include "Led.h"
#include "Pulse.h"

PixelRing::PixelRing(uint8_t pin, uint8_t numberOfLEDs) {
  _ring = Adafruit_NeoPixel(numberOfLEDs, pin, NEO_GRB + NEO_KHZ800);
  _numberOfLEDs = numberOfLEDs;
  _animation = new Flourish(numberOfLEDs, 0, 0, 0);
}

bool PixelRing::animationComplete() {
  return _animation->complete();
}

void PixelRing::begin() {
  _ring.begin();
  _ring.setBrightness(255);
  _ring.show();
}

void PixelRing::flourish(uint8_t red, uint8_t green, uint8_t blue) {
  setAnimation(new Flourish(_numberOfLEDs, red, green, blue));
}

void PixelRing::pulse(uint8_t red, uint8_t green, uint8_t blue) {
  setAnimation(new Pulse(_numberOfLEDs, red, green, blue));
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

void PixelRing::setAnimation(Animation* animation) {
  delete _animation;
  _animation = animation;
}
