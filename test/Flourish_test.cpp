#include "../src/Flourish.h"
#include "gtest/gtest.h"

namespace {
  TEST(FlourishTest, construction) {
    EXPECT_NO_THROW(Flourish(4, 0, 0, 0));
  }

  TEST(FlourishTest, completeWhenJustStarted) {
    Flourish sut = Flourish(4, 0, 0, 0);
    EXPECT_FALSE(sut.complete());
  }

  // Test(FlourishTest, renderWhenJustStarted) {
  //   EXPECT_COUNT
  // }
}
