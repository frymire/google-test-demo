
#pragma once
#include "pch.h"

class Counter {

private:
	int count_ = 0;

public:
	Counter();
	int get_count();
	void increment();
};
