#include "../Pulse.h"
#include "../Led.h"
#include "gtest/gtest.h"
#include <vector>

namespace {
  TEST(PulseTest, construction) {
    ASSERT_NO_THROW(new Pulse(4, 255, 0, 0));
  }

  TEST(PulseTest, completeWhenJustStarted) {
    Pulse* sut = new Pulse(4, 255, 0, 0);
    ASSERT_TRUE(sut->complete());
  }

  TEST(FlourishTest, renderWhenJustStartedShouldReset) {
    Pulse* sut = new Pulse(4, 255, 0, 0);
    std::vector<Led> leds = sut->render();

    ASSERT_EQ(4, leds.size());
    ASSERT_EQ(Led(0, 255, 0, 0), leds[0]);
    ASSERT_EQ(Led(1, 255, 0, 0), leds[1]);
    ASSERT_EQ(Led(2, 255, 0, 0), leds[2]);
    ASSERT_EQ(Led(3, 255, 0, 0), leds[3]);
  }

  TEST(FlourishTest, renderWhenAtMidpoint) {
    Pulse* sut = new Pulse(4, 255, 0, 0);
    std::vector<Led> leds = sut->render();

    for (int i=0; i<8; i++) {
      sut->tick();
    }

    ASSERT_EQ(4, leds.size());
    ASSERT_EQ(Led(0, 127, 0, 0), leds[0]);
    ASSERT_EQ(Led(1, 127, 0, 0), leds[1]);
    ASSERT_EQ(Led(2, 127, 0, 0), leds[2]);
    ASSERT_EQ(Led(3, 127, 0, 0), leds[3]);
  }
}
