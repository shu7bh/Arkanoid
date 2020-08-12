#include "Ball.h"

Ball::Ball(const float t, const float l, const float b, const float r, const Color c)
	: rect(t, l, b, r, c) 
{
	vx = 1.5;
	vy = 1.5;
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

bool Ball::hitRect(const Rect& object)
{
	if ((rect.bottom >= object.top &&
		rect.left >= object.left &&
		rect.bottom <= object.bottom &&
		rect.left <= object.right)
		||
		(rect.top >= object.top &&
		rect.left >= object.left &&
		rect.top <= object.bottom &&
		rect.left <= object.right
		)
		||
		(rect.bottom >= object.top &&
		rect.right >= object.left &&
		rect.bottom <= object.bottom &&
		rect.right <= object.right)
		||
		(rect.top >= object.top &&
		rect.right >= object.left &&
		rect.top <= object.bottom &&
		rect.right <= object.right
		))
	{
		vy = -vy;
		return true;
	}
	return false;
	/*
	vx = (vx + 5*v) / 6  

	always consider the player velocity is constant
	
	*/
}

void Ball::draw(Graphics& gfx) const
{
	int rad = (rect.right - rect.left) / 2;
	int cx = (rect.right + rect.left) / 2;
	int cy = (rect.bottom + rect.top) / 2;

	for (int i = int(rect.left); i <= int(rect.right); ++i)
		for (int j = int(rect.top); j <= int(rect.bottom); ++j)
			if ((cx - i) * (cx - i) + (cy - j) * (cy - j) <= rad * rad)
				gfx.PutPixel(i, j, rect.color);
}
