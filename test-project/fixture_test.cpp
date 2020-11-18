
#include "pch.h"

// Define a test fixture that will be created fresh for each test. 
class ArithmeticTest: public testing::Test {

protected:
  const int x;
  const int y;

  // Using the constructor to initialize the data is preferred over the SetUp(), because it allows us to use 
  // const data members, and any subclass constructors will first call this automatically. Use SetUp() and 
  // TearDown() if: 1) you need to call virtual functions, 2) you want to call ASSERT_* macros during fixture
  // creation, or 3) the tear-down operation could throw an exception.
  ArithmeticTest() : x(5), y(7) { cout << "ArithmeticTest.ArithmeticTest()" << endl; }

  // Be sure to define SetUp() and not Setup(). Use override to protect against this error.
  void SetUp() override { cout << "ArithmeticTest.SetUp()" << endl; }

  void TearDown() override { cout << "ArithmeticTest.TearDown()" << endl; }

  ~ArithmeticTest() override { cout << "ArithmeticTest.~ArithmeticTest()" << endl; }
};

// Use TEST_F() instead of TEST() for a test fixture.
TEST_F(ArithmeticTest, AddsCorrectly) {
  EXPECT_EQ(12, x + y);
}

TEST_F(ArithmeticTest, SubtractsCorrectly) {
  EXPECT_EQ(-2, x - y);
}
