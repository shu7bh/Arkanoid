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

void Ball::hitPlayer(const Rect& player)
{
	if (rect.bottom >= player.top - vy &&
		rect.left >= player.left - vx &&
		rect.bottom <= player.bottom - vy &&
		rect.left <= player.right - vx)
		vy = -vy;
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
