#include "Time.h"

Time::Time()
{
	before = std::chrono::steady_clock::now();
}

const float Time::getExecTime()
{
	const auto  current = std::chrono::steady_clock::now();
	const std::chrono::duration<float> duration = current - before;
	before = current;
	totalTime += duration.count();
	return duration.count();
}