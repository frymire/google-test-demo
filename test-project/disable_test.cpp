
#include "pch.h"

// Prepend "DISABLED_" to a test to disable it. This is better than commenting it out, since it will still be compiled.
TEST(CounterTest, DISABLED_TestIDontWantRightNow) {
  EXPECT_TRUE(false);
}

// Similarly, prepend "DISABLED_" to a test suite to disable it.
TEST(DISABLED_DisabledTest, DummyTest1) {
  EXPECT_TRUE(false);
}

// Prepending "DISABLED_" to either the suite name or the test name works, but you still have to do it for each test.
TEST(DISABLED_DisabledTest, DummyTest2) {
  EXPECT_TRUE(false);
}

// Run with the --gtest_also_run_disabled_tests option to run disabled tests despite these labels.
