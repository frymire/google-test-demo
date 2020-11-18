
#include "pch.h"

// In Visual Studio, you can skip the the main() by setting...
//   Project Properties -> Referenced Packages -> GoogleTest -> Use Google Test's main function -> Yes
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv); // parses the command line for googletest flags
  int result = RUN_ALL_TESTS();
  cout << "Note: some tests are meant to fail in this demo." << endl;
  return result;
}
