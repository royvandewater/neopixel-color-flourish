#include "Flourish.h"

Flourish::Flourish(uint8_t numLEDs, uint8_t red, uint8_t green, uint8_t blue) {
  _numLEDs = numLEDs;
  _red = red;
  _green = green;
  _blue = blue;
}

bool Flourish::complete() {
  return false;
}

std::list<Frame> Flourish::render() {
  std::list<Frame> frames = std::list<Frame>();

  for (int i = 0; i < _numLEDs; i++) {
    Frame frame = {0, 0, 0};
    frames.push_back(frame);
  }

  return frames;
}
