#pragma once
#include <chrono>

class Time
{
private:
	std::chrono::steady_clock::time_point before;
	float totalTime = 0.0f;
public:
	Time();
	const float getExecTime();
	const float TotalTime() const { return totalTime; }
};

