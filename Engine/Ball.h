#pragma once
#include "Rect.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(const float t, const float l, const float b, const float r, const Color c = Colors::Yellow);
	Ball(const float t, const float l, const Color c = Colors::Yellow);
	void update(const float dt, const float totalTime);
	void keepInFrame(int top, int left, int right);
	const Rect& getRect() const { return rect; }
	bool touchedBottom(int bottom);
	bool hitBlock(const Rect& object, const float dt);
	void draw(Graphics& gfx) const;
	float vx, vy;
	void hitPlayer(const Rect& player, const float dt);
	static constexpr int width = 10;
	static int score;
private:
	Rect rect;
	

};