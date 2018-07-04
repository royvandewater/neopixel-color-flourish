#include "../Flourish.h"
#include "../Led.h"
#include "gtest/gtest.h"
#include <vector>

namespace {
  TEST(FlourishTest, construction) {
    ASSERT_NO_THROW(Flourish(4, 255, 0, 0));
  }

  TEST(FlourishTest, completeWhenJustStarted) {
    Flourish sut = Flourish(4, 255, 0, 0);
    ASSERT_FALSE(sut.complete());
  }

  TEST(FlourishTest, completeWhenFinished) {
    Flourish sut = Flourish(4, 255, 0, 0);
    for (int i=0; i<5; i++) { // phase 1
      sut.tick();
    }
    for (int i=0; i<6; i++) { // phase 2
      sut.tick();
    }
    ASSERT_TRUE(sut.complete());
  }

  TEST(FlourishTest, renderWhenJustStartedShouldReset) {
    Flourish sut = Flourish(4, 255, 0, 0);
    std::vector<Led> leds = sut.render();

    ASSERT_EQ(4, leds.size());
    ASSERT_EQ(Led(0, 0, 0, 0), leds[0]);
    ASSERT_EQ(Led(1, 0, 0, 0), leds[1]);
    ASSERT_EQ(Led(2, 0, 0, 0), leds[2]);
    ASSERT_EQ(Led(3, 0, 0, 0), leds[3]);
  }

  TEST(FlourishTest, renderOneFrameIn) {
    Flourish sut = Flourish(4, 255, 0, 0);
    sut.tick();
    std::vector<Led> leds = sut.render();

    ASSERT_EQ(4, leds.size());
    ASSERT_EQ(Led(0, 255, 0, 0), leds[0]);
    ASSERT_EQ(Led(1, 0, 0, 0), leds[1]);
    ASSERT_EQ(Led(2, 0, 0, 0), leds[2]);
    ASSERT_EQ(Led(3, 0, 0, 0), leds[3]);
  }

  TEST(FlourishTest, renderLastFrameOfFirstPhase) {
    Flourish sut = Flourish(4, 255, 0, 0);
    for (int i=0; i<5; i++) {
      sut.tick();
    }
    std::vector<Led> leds = sut.render();

    ASSERT_EQ(4, leds.size());
    ASSERT_EQ(Led(0, 255, 0, 0), leds[0]);
    ASSERT_EQ(Led(1, 255, 0, 0), leds[1]);
    ASSERT_EQ(Led(2, 255, 0, 0), leds[2]);
    ASSERT_EQ(Led(3, 255, 0, 0), leds[3]);
  }

  TEST(FlourishTest, renderMiddleFrameOfSecondPhase) {
    Flourish sut = Flourish(4, 255, 0, 0);
    for (int i=0; i<5; i++) { // First Phase
      sut.tick();
    }
    for (int i=0; i<3; i++) { // Halfway through second
      sut.tick();
    }
    std::vector<Led> leds = sut.render();

    ASSERT_EQ(4, leds.size());
    ASSERT_EQ(Led(0, 255, 255, 255), leds[0]);
    ASSERT_EQ(Led(1, 255, 255, 255), leds[1]);
    ASSERT_EQ(Led(2, 255, 255, 255), leds[2]);
    ASSERT_EQ(Led(3, 255, 255, 255), leds[3]);
  }

  TEST(FlourishTest, renderPartwayThroughSecondPhase) {
    Flourish sut = Flourish(4, 255, 0, 0);
    for (int i=0; i<5; i++) { // First Phase
      sut.tick();
    }
    for (int i=0; i<1; i++) { // 1 third way through second phase
      sut.tick();
    }
    std::vector<Led> leds = sut.render();

    ASSERT_EQ(4, leds.size());
    ASSERT_EQ(Led(0, 255, 85, 85), leds[0]);
    ASSERT_EQ(Led(1, 255, 85, 85), leds[1]);
    ASSERT_EQ(Led(2, 255, 85, 85), leds[2]);
    ASSERT_EQ(Led(3, 255, 85, 85), leds[3]);
  }

  TEST(FlourishTest, renderMostWayThroughSecondPhase) {
    Flourish sut = Flourish(4, 255, 0, 0);
    for (int i=0; i<5; i++) { // First Phase
      sut.tick();
    }
    for (int i=0; i<4; i++) { // 2 third way through second phase
      sut.tick();
    }
    std::vector<Led> leds = sut.render();

    ASSERT_EQ(4, leds.size());
    ASSERT_EQ(Led(0, 255, 170, 170), leds[0]);
    ASSERT_EQ(Led(1, 255, 170, 170), leds[1]);
    ASSERT_EQ(Led(2, 255, 170, 170), leds[2]);
    ASSERT_EQ(Led(3, 255, 170, 170), leds[3]);
  }
}
