#pragma once

class Counter {

private:
	int count_ = 0;

public:
	Counter();
	int get_count();
	void increment();
};
