#include "../src/Flourish.h"
#include "../src/Led.h"
#include "gtest/gtest.h"
#include <vector>

namespace {
  TEST(FlourishTest, construction) {
    EXPECT_NO_THROW(Flourish(4, 0, 0, 0));
  }

  TEST(FlourishTest, completeWhenJustStarted) {
    Flourish sut = Flourish(4, 0, 0, 0);
    EXPECT_FALSE(sut.complete());
  }

  TEST(FlourishTest, renderWhenJustStarted) {
    Flourish sut = Flourish(4, 255, 0, 0);
    std::vector<Led> leds = sut.render();

    EXPECT_EQ(4, leds.size());
    EXPECT_EQ(Led(0, 0, 0, 0), leds[0]);
    EXPECT_EQ(Led(1, 0, 0, 0), leds[1]);
    EXPECT_EQ(Led(2, 0, 0, 0), leds[2]);
    EXPECT_EQ(Led(3, 0, 0, 0), leds[3]);
  }

  // TEST(FlourishTest, renderOneFrameIn) {
  //   Flourish sut = Flourish(4, 255, 0, 0);
  //   sut.tick();
  //   std::vector<Led> leds = sut.render();
  //
  //   EXPECT_EQ(4, leds.size());
  //   EXPECT_EQ(Led(0, 255, 0, 0), leds[0]);
  //   EXPECT_EQ(Led(1, 0, 0, 0), leds[1]);
  //   EXPECT_EQ(Led(2, 0, 0, 0), leds[2]);
  //   EXPECT_EQ(Led(3, 0, 0, 0), leds[3]);
  // }
}
