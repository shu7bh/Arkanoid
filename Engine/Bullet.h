#pragma once
#include "Graphics.h"
class Bullet
{
public:
	int x, y;
	const int vy = -3;
	Bullet(int posx, int posy) { x = posx, y = posy; }
	void draw(Graphics gfx);
	void update() { y += vy; }
};

