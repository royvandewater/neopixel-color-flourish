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
  return _currentFrameNumber >= (_numLeds + 6);
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
  if (_currentFrameNumber <= (_numLeds + 1) || _currentFrameNumber > (_numLeds + 7)) {
    return Led(ledNumber, _red, _green, _blue);
  }

  return Led(ledNumber, Flourish::_colorComponent(_red), Flourish::_colorComponent(_green), Flourish::_colorComponent(_blue));
}

uint8_t Flourish::_colorComponent(uint8_t color) {
  uint16_t diff = 255 - color;
  uint16_t step = diff / 3;
  uint16_t stepNumber = _currentFrameNumber - (_numLeds + 1);

  if (stepNumber > 3) {
    return color + (step * (6 - stepNumber));
  }

  uint16_t colorComponent = color + (step * stepNumber);
  if (colorComponent > 255) {
    return 255;
  }
  return colorComponent;
}

void Flourish::tick() {
  _currentFrameNumber += 1;
}
