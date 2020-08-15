#pragma once
#include "Graphics.h"
#include "Rect.h"
#include "Colors.h"

class Bullet
{	
	Rect rect;
	const float vy = -3.0 * 60.0f;
	static constexpr int height = 4;
	static constexpr int width = 2;
public:
	Bullet(const float t, const float l);
	const Rect& getRect() { return rect; }
	void draw(Graphics gfx);
	void update(const float dt);
	bool isHit(const Rect& block, bool& isblock, const float dt);
};

