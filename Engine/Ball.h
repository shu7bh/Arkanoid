#pragma once
#include "Rect.h"

class Ball
{
public:
	Ball(const float t, const float l, const float b, const float r, const Color c = Colors::White);
	void update();
	void keepInFrame(int top, int left, int right);
	const Rect& getRect() const { return rect; }
	bool touchedBottom(int bottom);

private:
	Rect rect;
	float vx, vy;

};