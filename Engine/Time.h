#pragma once
#include <chrono>

class Time
{
private:
	std::chrono::steady_clock::time_point before;
public:
	Time();
	const float getExecTime();
};

