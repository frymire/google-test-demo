
#include "Counter.h"

Counter::Counter() { count_ = 5; }
void Counter::increment() { count_++; }
int Counter::get_count() { return count_; }
