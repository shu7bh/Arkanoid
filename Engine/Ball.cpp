#include "Ball.h"

Ball::Ball(const float t, const float l, const float b, const float r, const Color c)
	: rect(t, l, b, r, c) 
{
	vx = 2;
	vy = 2;
}

void Ball::update()
{
	rect.update(vx, vy);
}

void Ball::keepInFrame(int top, int left, int right)
{
	if (int(rect.top) < top - int(vy))
		vy = -vy;
	if (int(rect.left) < left - int(vx) || int(rect.right) >= right - int(vx))
		vx = -vx;
}

bool Ball::touchedBottom(int bottom)
{
	if (int(rect.bottom >= bottom))
		return true;
	return false;
}
