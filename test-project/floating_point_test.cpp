
#include "pch.h"

TEST(FloatingPointTest, ShouldPassWithSlightNumericalErrors) {

  // It's preferred that you explicitly specify an acceptable error range like this.
  EXPECT_NEAR(1.0, 1.1, 0.2);
  EXPECT_NEAR(-5.0, -5.1, 0.2);

  // Alternatively, you can rely on their built-in definition of "close". 
  EXPECT_FLOAT_EQ(1.0f, 1.0f + 1e-7f);
  //EXPECT_FLOAT_EQ(1.0f, 1.0f + 1e-6f); // fails
  EXPECT_DOUBLE_EQ(2.0, 2.0 + 1e-15);
  //EXPECT_DOUBLE_EQ(2.0, 2.0 + 1e-14); // fails

  // Check that a float/double is less than or approximately equal to another.
  EXPECT_PRED_FORMAT2(testing::FloatLE, 1.5, 2.0);
  EXPECT_PRED_FORMAT2(testing::DoubleLE, 1.5, 2.0);
}
