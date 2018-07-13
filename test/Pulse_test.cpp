#include "../Pulse.h"
#include "../Led.h"
#include "gtest/gtest.h"
#include <vector>

namespace {
  TEST(PulseTest, construction) {
    ASSERT_NO_THROW(Pulse(4, 255, 0, 0));
  }

  TEST(PulseTest, completeWhenJustStarted) {
    Pulse sut = Pulse(4, 255, 0, 0);
    ASSERT_FALSE(sut.complete());
  }

  TEST(PulseTest, completeWhen4LoopsIn) {
    Pulse sut = Pulse(4, 255, 0, 0);
    for (int i=0; i<(4 * 8); i++) sut.tick();
    sut.tick();
    ASSERT_TRUE(sut.complete());
  }

  TEST(PulseTest, renderWhenJustStarted) {
    Pulse sut = Pulse(4, 255, 0, 0);
    std::vector<Led> leds = sut.render();

    ASSERT_EQ(4, leds.size());
    ASSERT_EQ(Led(0, 255, 0, 0), leds[0]);
    ASSERT_EQ(Led(1, 255, 0, 0), leds[1]);
    ASSERT_EQ(Led(2, 255, 0, 0), leds[2]);
    ASSERT_EQ(Led(3, 255, 0, 0), leds[3]);
  }

  TEST(PulseTest, renderWhenAtMidpoint) {
    Pulse sut = Pulse(4, 255, 0, 0);

    for (int i=0; i<8; i++) {
      sut.tick();
    }

    std::vector<Led> leds = sut.render();

    ASSERT_EQ(4, leds.size());
    ASSERT_EQ(Led(0, 128, 0, 0), leds[0]);
    ASSERT_EQ(Led(1, 128, 0, 0), leds[1]);
    ASSERT_EQ(Led(2, 128, 0, 0), leds[2]);
    ASSERT_EQ(Led(3, 128, 0, 0), leds[3]);
  }

  TEST(PulseTest, renderWhenAtMidpointOfSecondCycle) {
    Pulse sut = Pulse(4, 255, 0, 0);

    for (int i=0; i<24; i++) {
      sut.tick();
    }

    std::vector<Led> leds = sut.render();

    ASSERT_EQ(4, leds.size());
    ASSERT_EQ(Led(0, 128, 0, 0), leds[0]);
    ASSERT_EQ(Led(1, 128, 0, 0), leds[1]);
    ASSERT_EQ(Led(2, 128, 0, 0), leds[2]);
    ASSERT_EQ(Led(3, 128, 0, 0), leds[3]);
  }
}
