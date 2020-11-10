
/*
   A demonstration using Google Test to test code in another Visual Studio project.

   Note: After creating the test project, add the target project as a reference. Even after doing that,
   however, you have to explicitly add obj and lib files to the build path if the target project doesn't
   export the the functions you want to test.

   See: https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019
 */

#include "pch.h"
#include "Counter.h"

TEST(Counter_Test, ShouldReturn5AfterInstantiation) {
  Counter c = Counter();
  EXPECT_EQ(5, c.get_count());
}

TEST(Counter_Test, ShouldPassABunchOfRandomTests) {
  Counter c = Counter();
  EXPECT_NE(4, c.get_count());
  EXPECT_FALSE(0 == 1);
  EXPECT_LT(1, 2);
  EXPECT_GT(2, 1);
  EXPECT_GE(2, 2);
  EXPECT_STREQ("Hi", "Hi");
  EXPECT_STRNE("Hi", "HI");
  EXPECT_STRCASEEQ("HI", "hi");
}

// In Visual Studio, you can skip the following code by setting...
//   Project Properties -> Referenced Packages -> GoogleTest -> Use Google Test's main function -> Yes
//int main(int argc, char **argv) {
//  ::testing::InitGoogleTest(&argc, argv);
//  return RUN_ALL_TESTS();
//}
