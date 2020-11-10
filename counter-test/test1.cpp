
/*
   A demonstration using googletest to test code in another Visual Studio project.

   Note: After creating the test project, add the target project as a reference. Even after doing that,
   however, you have to explicitly add obj and lib files to the build path if the target project doesn't
   export the the functions you want to test.

   See: https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019
 */

#include "pch.h"
#include "Counter.h"

TEST(CounterTest, ShouldReturn5AfterInstantiation) {
  Counter c = Counter();
  EXPECT_EQ(5, c.get_n());
}

TEST(CounterTest, EasyTest) {
  cout << "Hi." << endl;
  EXPECT_TRUE(2 == 1);
}

// In Visual Studio, you can skip the following code by setting...
//   Project Properties -> Referenced Packages -> GoogleTest -> Use Google Test's main function -> Yes
//int main(int argc, char **argv) {
//  ::testing::InitGoogleTest(&argc, argv);
//  return RUN_ALL_TESTS();
//}
