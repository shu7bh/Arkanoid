#pragma once
#include "Rect.h"
#include "MainWindow.h"

class Player
{
public:
	Player(const float t, const float l, const float r, const float b, const int rd, const int grn, const int bl);
	Player(const float t, const float l, const float r, const float b, const Color c = Colors::LightGray);
	Player(const float t, const float l, const Color c = Colors::LightGray);
	void update();
	void ChangeVelocity(MainWindow& wnd);
	const Rect& getRect() const { return rect; }
	void KeepInFrame(int Left, int Right);
	float v;

	static constexpr int width = 70, height = 10;
private:
	Rect rect;
};