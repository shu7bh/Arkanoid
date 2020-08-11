#pragma once
#include "Rect.h"
#include "MainWindow.h"

class Player
{
public:
	Player(float t, float l, float r, float b, int rd, int grn, int bl);
	Player(float t, float l, float r, float b, Color c = Colors::White);
	void update();
	void ChangeVelocity(MainWindow& wnd);
	const Rect& getRect() const { return rect; }
	void KeepInFrame(int Left, int Right);
private:
	Rect rect;
	float v;
};