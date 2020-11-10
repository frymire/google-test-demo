
#include "pch.h"
#include "Counter.h"

int main() {
  Counter my_counter = Counter();
  cout << "Hello, cruel world.\n" << endl;
  cout << "Counter = " << my_counter.get_count() << endl;
}
