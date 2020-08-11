#pragma once
#include "Colors.h"
#include "Graphics.h"
class Rect
{
	protected: 
		float top, left, bottom, right;
		Color color;
	public:
		Rect();
		Rect(const float t, const float l, const float b, const float r, const int rd, const int grn, const int bl);
		Rect(const float t, const float l, const float b, const float r, const Color c);
		Rect(const float t, const float l, const int width, const int height, Color c = Colors::White);
		bool isHit = false;
		void draw(Graphics& gfx) const;
};

