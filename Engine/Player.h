#pragma once
#include "Rect.h"

class Player
{
public:
	Player(float t, float l, float r, float b, int rd, int grn, int bl);

private:
	Rect block;
	float v;


};