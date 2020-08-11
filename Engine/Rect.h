#pragma once
#include "Colors.h"
#include "Graphics.h"
class Rect
{
	protected: 
		float top, left, right, bottom;
		Color color;
	public:
		Rect();
		Rect(const float t, const float l, const float r, const float b, const int rd, const int grn, const int bl);
		Rect(const float t, const float l, const float r, const float b, const Color c);
		Rect(const float t, const float l, const int width, const int height, Color c = Colors::White);
		bool isHit = false;
		void draw(Graphics& gfx) const;

};

