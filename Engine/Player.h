#pragma once
#include "Rect.h"

class Player
{
public:
	Player(float t, float l, float r, float b, int rd, int grn, int bl);
	Player(float t, float l, float r, float b, Color c = Colors::White);

	const Rect& getRect() const { return rect; }
private:
	Rect rect;
	float v;
};