#pragma once
#include "Rect.h"

class Block
{
public:
	Block(float t, float l, float r, float b, int rd, int grn, int bl);
	Block(float t, float l, float r, float b, Color c = Colors::White);

	const Rect& getRect() const { return rect; }
private:
	Rect rect;
	//ollo
};

