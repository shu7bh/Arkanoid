#pragma once
#include "Rect.h"

class Ball
{
public:
	Ball(const float t, const float l, const float b, const float r, const Color c = Colors::White);
private:
	Rect rect;
	float vx, vy;

	void update();
};