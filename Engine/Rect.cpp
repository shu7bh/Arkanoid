#include "Rect.h"
#include "Graphics.h"
Rect::Rect() 
	: color(Colors::White)
{
	top = 0, right = 0, bottom = 0, left = 0;
}

Rect::Rect(const float t, const float l, const float r, const float b, const int rd, const int grn, const int bl)
	: color(rd, grn, bl)
{
	top = t, bottom = b, left = l, right = r;
}

Rect::Rect(const float t, const float l, const float r, const float b, const Color c)
	: color(c)
{
	top = t, bottom = b, left = l, right = r;
}

Rect::Rect(const float t, const float l, const int width, const int height, Color c)
	: color(c)
{
	top = t, left = l;
	bottom = t + height, right = left + width;
}

void Rect::draw(Graphics& gfx) const
{
	for (int i = int(top); i <= int(bottom); ++i)
		for (int j = int(left); j <= int(right); ++j)
			gfx.PutPixel(i, j, color);
}

