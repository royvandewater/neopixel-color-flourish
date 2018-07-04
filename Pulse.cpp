#include "Pulse.h"

Pulse::Pulse() {
  _numLeds = 0;
  _red = 0;
  _green = 0;
  _blue = 0;
  _currentFrameNumber = 0;
}

Pulse::Pulse(uint8_t numLeds, uint8_t red, uint8_t green, uint8_t blue) {
  _numLeds = numLeds;
  _red = red;
  _green = green;
  _blue = blue;
  _currentFrameNumber = 0;
}

bool Pulse::complete() {
  return true;
}

std::vector<Led> Pulse::render() {
  std::vector<Led> leds = std::vector<Led>();

  for (int i=0; i<_numLeds; i++) {
    leds.push_back(this->_renderLed(i));
  }

  return leds;
}

void Pulse::tick() {
  _currentFrameNumber += 1;
}

Led Pulse::_renderLed(uint32_t ledNumber) {
  return Led(ledNumber, _red, _green, _blue);
  // return Led(ledNumber, Pulse::_colorComponent(_red), PUlse::_colorComponent(_green), Pulse::_colorComponent(_blue));
}

uint8_t Pulse::_colorComponent(uint8_t color) {
  return color;
  // uint16_t diff = 255 - color;
  // uint16_t step = diff / 3;
  // uint16_t stepNumber = _currentFrameNumber - (_numLeds + 1);
  //
  // if (stepNumber > 3) {
  //   return color + (step * (6 - stepNumber));
  // }
  //
  // uint16_t colorComponent = color + (step * stepNumber);
  // if (colorComponent > 255) {
  //   return 255;
  // }
  // return colorComponent;
}
