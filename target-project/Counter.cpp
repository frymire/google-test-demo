
#include "Counter.h"

Counter::Counter() { count_ = 5; }
void Counter::Increment() { count_++; }
int Counter::GetCount() { return count_; }
