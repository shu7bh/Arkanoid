#include "Bullet.h"

Bullet::Bullet(const float t, const float l)
	: rect(t, l, height, width, Colors::White) {}

void Bullet::draw(Graphics gfx)
{
	rect.draw(gfx);
}

void Bullet::update(const float dt) { 
	rect.update(0, vy * dt); 
}

bool Bullet::isHit(const Rect& block, bool& isblock, const float dt)
{
	if (rect.top <= -vy * dt) {
		isblock = false;
		return true;
	}

	else if (rect.top + vy * dt > block.top &&
		rect.top + vy * dt <= block.bottom &&
		rect.left >= block.left &&
		rect.right <= block.right)
	{
		isblock = true;
		return true;
	}
	return false;
}
