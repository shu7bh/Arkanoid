#pragma once
#include "Rect.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(const float t, const float l, const float b, const float r, const Color c = Colors::Yellow);
	Ball(const float t, const float l, const Color c = Colors::Yellow);
	void update(const float dt);
	void keepInFrame(int top, int left, int right);
	const Rect& getRect() const { return rect; }
	bool touchedBottom(int bottom);
	bool hitBlock(const Rect& object);
	void draw(Graphics& gfx) const;
	float vx, vy;
	bool hitPlayer(const Rect& player);
	static constexpr int width = 10;
private:
	Rect rect;

};