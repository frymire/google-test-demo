
/*
   A demonstration using Google Test to test code in another Visual Studio project.

   Note: After creating the test project, add the target project as a reference. Even after doing that,
   however, you have to explicitly add obj and lib files to the build path if the target project doesn't
   export the the functions you want to test.

   See: https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019
 */

#include "pch.h"
#include "Counter.h"

TEST(StringTest, ModifiedStringsShouldBeEquivalent) {
  EXPECT_STREQ("Hi", "Hi");
  EXPECT_STRNE("Hi", "HI");
  EXPECT_STRCASEEQ("HI", "hi"); // "CASE" means the call will ignore case
}

TEST(StringTest, PointerEqualityOnSeparateStringsWithIdenticalDataShouldFail) {
  const char* string1 = "Hey";
  const char* string2 = "Hey";
  EXPECT_STREQ(string1, string2); // pass
  EXPECT_EQ(string1, string2); // fail, it's checking *pointer* equality
}

TEST(StringTest, StringsShouldBeNull) {

  const char* string1 = nullptr;
  EXPECT_EQ(string1, nullptr); // pass

  const char* string2 = NULL;
  EXPECT_EQ(string2, nullptr); // pass
  //EXPECT_EQ(string2, NULL); // compile error calling EXPECT_EQ with NULL
  EXPECT_STREQ(string2, NULL); // okay calling EXPECT_STREQ to compare a C-style string with NULL

  const char* string3 = "";
  EXPECT_EQ(string3, nullptr); // fail, this is an empty string at a valid address
  }
