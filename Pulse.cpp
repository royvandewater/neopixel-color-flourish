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
  return _currentFrameNumber > (8 * 4);
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
  return Led(ledNumber, Pulse::_colorComponent(_red), Pulse::_colorComponent(_green), Pulse::_colorComponent(_blue));
}

uint8_t Pulse::_colorComponent(uint8_t color) {
  uint8_t diff = color / 2;
  float percent = Pulse::_percent();

  return color - (percent * diff);
}

float Pulse::_percent() {
  uint8_t step = Pulse::_step();

  if (step <= 8) return (float)step / (float)8;
  return (float)(16-step) / (float)8;
}

uint8_t Pulse::_step() {
  if (_currentFrameNumber == 0) return 0;
  if (_currentFrameNumber % 16 == 0) return 16;
  return _currentFrameNumber % 16;
}
