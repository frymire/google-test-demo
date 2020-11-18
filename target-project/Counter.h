
#pragma once
#include "pch.h"

class Counter {

private:
	int count_ = 0;

public:
	Counter();
	int GetCount();
	void Increment();
};
