#pragma once
#include "Rect.h"
#include "MainWindow.h"

class Player
{
public:
	Player(float t, float l, float r, float b, int rd, int grn, int bl);
	Player(float t, float l, float r, float b, Color c = Colors::Yellow);
	void ChangeVelocity(MainWindow& wnd);
	const Rect& getRect() const { return rect; }
	void update();
private:
	Rect rect;
	float v;
	
};