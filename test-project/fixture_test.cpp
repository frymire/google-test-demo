
#include "pch.h"

// Define a test fixture. A separate instance will be created for each test. 
class ArithmeticTest: public testing::Test {

protected:

  const int x;
  const int y;

  // Just for fun, get the name of the current test suite (called a "test case" in Google Test) and test.
  const testing::TestInfo* const test_info = testing::UnitTest::GetInstance()->current_test_info();
  const char* test_suite_name = test_info->test_case_name();
  const char* test_name = test_info->name();

  // Using the constructor to initialize the data is preferred over the SetUp(), because it allows us to use 
  // const data members, and any subclass constructors will first call this automatically. Use SetUp() and 
  // TearDown() if: 1) you need to call virtual functions, 2) you want to call ASSERT_* macros during fixture
  // creation, or 3) the tear-down operation could throw an exception.
  ArithmeticTest() : x(5), y(7) {  
    cout << "Test suite " << test_suite_name << ", test " << test_name << "..." << endl;
    cout << "\tArithmeticTest()" << endl;
  }

  // Be sure to define SetUp() and not Setup(). Use override to protect against this error.
  void SetUp() override { cout << "\tSetUp()" << endl; }
  void TearDown() override { cout << "\tTearDown()" << endl; }
  ~ArithmeticTest() override { cout << "\t~ArithmeticTest()" << endl; }
};

// Use TEST_F() instead of TEST() for a test fixture.
TEST_F(ArithmeticTest, AddsCorrectly) {
  EXPECT_EQ(12, x + y);
}

TEST_F(ArithmeticTest, SubtractsCorrectly) {
  EXPECT_EQ(-2, x - y);
}
