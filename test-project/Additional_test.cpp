
/*
   A demonstration using Google Test to test code in another Visual Studio project.

   Note: After creating the test project, add the target project as a reference. Even after doing that,
   however, you have to explicitly add obj and lib files to the build path if the target project doesn't
   export the the functions you want to test.

   See: https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019
 */

#include "pch.h"
#include "Counter.h"

TEST(Additional_Test, ShouldPassAnEasyTestInADifferentFile) {
  EXPECT_TRUE(2 == 1);
}
