#include "Bullet.h"

void Bullet::draw(Graphics gfx)
{
	gfx.PutPixel(x, y, Colors::White);
	gfx.PutPixel(x, y + 1, Colors::White);
}
