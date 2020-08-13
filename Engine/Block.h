#pragma once
#include "Rect.h"
#include <random>
#include <ctime>

class Block
{
public:
	Block(float t, float l, float b, float r, int rd, int grn, int bl);
	Block(float t, float l, float b, float r, Color c = Colors::White);
	const Rect& getRect() const { return rect; }
	const int HitCounter() const { return hitCounter; }
	void DecHitCounter() { --hitCounter, rect.color = colors[hitCounter]; }

	static constexpr int width = 50, height = 10;
private:

	int hitCounter = 1;
	static const std::vector<Color> colors;
	Rect rect;
	static std::default_random_engine generator;
	static std::uniform_int_distribution<int> values;
};

