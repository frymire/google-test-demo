
#include "pch.h"


// Define environments to enable us to do global setup and teardown for the entire test program.
// You might use this to initialize databases and such.

class MyEnvironment1: public testing::Environment {
public:
  ~MyEnvironment1() override {}
  void SetUp() override { cout << "Setting up MyEnvironment1()." << endl;  }
  void TearDown() override { cout << "Tearing down MyEnvironment1()." << endl; }
};

class MyEnvironment2: public testing::Environment {
public:
  ~MyEnvironment2() override {}
  void SetUp() override { cout << "Setting up MyEnvironment2()." << endl; }
  void TearDown() override { cout << "Tearing down MyEnvironment2()." << endl; }
};


/* 
    In Visual Studio, you can skip the the main() by setting...
      Project Properties -> Referenced Packages -> GoogleTest -> Use Google Test's main function -> Yes

    On the other hand, setting it up explicitly allows you to pass arguments to control how the test is run. 
    To see the options, do this...
      Project Properties -> Debugging -> Command Arguments -> "--help"

    For instance...
      --gtest_break_on_failure  breaks for debugging on each failure
      --gtest_brief=1  only shows test failures (doesn't work on this version)
      --gtest_repeat=[COUNT]  runs the tests COUNT times, use a negative number to repeat forever
      --gtest_shuffle  runs the tests in a random order to reveal bad dependencies among them
      --gtest_filter=FooTest.*  runs everything in test suite FooTest
      --gtest_filter=FooTest.*-FooTest.Bar  runs everything in test suite FooTest except FooTest.Bar
      --gtest_filter=FooTest.*:BarTest.*-FooTest.Bar:BarTest.Foo  Runs everything in test suite FooTest except FooTest.Bar 
                                                                  and everything in test suite BarTest except BarTest.Foo
*/
int main(int argc, char **argv) {

  // Parse the command line for Google Test flags.
  testing::InitGoogleTest(&argc, argv);

  // Register environment instances for the test program. They will setup in the order registered and teardown in the
  // opposite order. No need to define or register any environments if you have no global setup/teardown to do.
  testing::AddGlobalTestEnvironment(new MyEnvironment1);
  testing::AddGlobalTestEnvironment(new MyEnvironment2);

  int result = RUN_ALL_TESTS();
  cout << "Note: some tests are meant to fail in this demo." << endl;
  return result;
}
