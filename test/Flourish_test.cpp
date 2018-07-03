#include "../src/Flourish.h"
#include "gtest/gtest.h"
#include <list>

namespace {
  TEST(FlourishTest, construction) {
    EXPECT_NO_THROW(Flourish(4, 0, 0, 0));
  }

  TEST(FlourishTest, completeWhenJustStarted) {
    Flourish sut = Flourish(4, 0, 0, 0);
    EXPECT_FALSE(sut.complete());
  }

  TEST(FlourishTest, renderWhenJustStarted) {
    Flourish sut = Flourish(4, 0, 0, 0);
    std::list<Frame> frames = sut.render();

    EXPECT_EQ(4, frames.size());
  }
}
