#include "Ball.h"

Ball::Ball(const float t, const float l, const float b, const float r, const Color c)
	: rect(t, l, b, r, c) 
{
	vx = 0;
	vy = 0;
}

void Ball::update()
{
}
