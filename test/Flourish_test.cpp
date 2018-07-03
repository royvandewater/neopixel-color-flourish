#include "../src/Flourish.h"
#include "gtest/gtest.h"

namespace {
  TEST(FlourishTest, Construction) {
    EXPECT_NO_THROW(Flourish(0, 0, 0));
  }

  TEST(FlourishTest, CompleteWhenJustStarted) {
    Flourish sut = Flourish(0, 0, 0);
    EXPECT_FALSE(sut.complete());
  }
}
