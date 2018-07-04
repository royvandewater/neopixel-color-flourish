#ifndef Animation_h
#define Animation_h

#include <vector>
#include "Led.h"

class Animation {
public:
  virtual bool complete() = 0;
  virtual std::vector<Led> render() = 0;
  virtual void tick() = 0;
};

#endif
