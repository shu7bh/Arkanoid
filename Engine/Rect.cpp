#include "Rect.h"
#include "Graphics.h"
Rect::Rect() 
	: color(Colors::White)
{
	top = 0, right = 0, bottom = 0, left = 0;
}

Rect::Rect(const float t, const float l, const float b, const float r, const int rd, const int grn, const int bl)
	: color(rd, grn, bl)
{
	top = t, bottom = b, left = l, right = r;
}

Rect::Rect(const float t, const float l, const float b, const float r, const Color c)
	: color(c)
{
	top = t, bottom = b, left = l, right = r;
}

Rect::Rect(const float t, const float l, const int height, const int width, Color c)
	: color(c)
{
	top = t, left = l;
	bottom = t + height, right = left + width;
}

void Rect::draw(Graphics& gfx) const
{
	for (int i = int(left); i <= int(right); ++i)
		for (int j = int(top); j <= int(bottom); ++j)
			gfx.PutPixel(i, j, color);
}

void Rect::update(float vx, float vy)
{
	top += vy, bottom += vy, left += vx, right += vx;
}
