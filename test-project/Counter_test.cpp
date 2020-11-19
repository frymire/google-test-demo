
/*
   A demonstration using Google Test to test code in another Visual Studio project.

   Note: After creating the test project, add the target project as a reference. Even after doing that,
   however, you have to explicitly add obj and lib files to the build path if the target project doesn't
   export the the functions you want to test.

   See: https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019
 */

#include "pch.h"
#include "Counter.h"

// Use class naming convention for test suite names; don't use underscores (e.g. Counter_Test).
TEST(CounterTest, ShouldReturn5AfterInstantiation) {  
  Counter c = Counter();
  EXPECT_EQ(5, c.GetCount());
}

TEST(CounterTest, ShouldFailWithAMessage) {
  Counter c = Counter();
  EXPECT_EQ(4, c.GetCount()) << "Hey, I expected 4, but found " << c.GetCount();
}

TEST(CounterTest, ShouldPassABunchOfRandomTests) {
  Counter c = Counter();
  EXPECT_NE(4, c.GetCount());
  EXPECT_FALSE(0 == 1);
  EXPECT_LT(1, 2);
  EXPECT_GT(2, 1);
  EXPECT_GE(2, 2);
  // NOTE: If you want a failed assertion to be fatal, use ASSERT_* rather than EXPECT_*.
}
