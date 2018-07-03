#include "Flourish.h"
#include "Led.h"

Flourish::Flourish() {
  _numLeds = 0;
  _red = 0;
  _green = 0;
  _blue = 0;
  _currentFrameNumber = 0;
}

Flourish::Flourish(uint8_t numLeds, uint8_t red, uint8_t green, uint8_t blue) {
  _numLeds = numLeds;
  _red = red;
  _green = green;
  _blue = blue;
  _currentFrameNumber = 0;
}

bool Flourish::complete() {
  return _currentFrameNumber >= _numLeds;
}

std::vector<Led> Flourish::render() {
  std::vector<Led> leds = std::vector<Led>();

  for (int i = 0; i < _numLeds; i++) {
    leds.push_back(this->_renderLed(i));
  }

  return leds;
}

Led Flourish::_renderLed(uint32_t ledNumber) {
  if (_currentFrameNumber <= ledNumber) {
    return Led(ledNumber, 0, 0, 0);
  }
  return Led(ledNumber, _red, _green, _blue);
}

void Flourish::tick() {
  _currentFrameNumber += 1;
}
