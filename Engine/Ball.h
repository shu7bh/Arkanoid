#pragma once
#include "Rect.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(const float t, const float l, const float b, const float r, const Color c = Colors::White);
	void update();
	void keepInFrame(int top, int left, int right);
	const Rect& getRect() const { return rect; }
	bool touchedBottom(int bottom);
	void hitPlayer(const Rect& player);
	void draw(Graphics& gfx) const;

private:
	Rect rect;
	float vx, vy;

};