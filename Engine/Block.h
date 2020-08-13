#pragma once
#include "Rect.h"
#include <random>
#include <ctime>

class Block
{
public:
	Block(const float t, const float l, const float b, const float r, const int rd, const int grn, const int bl);
	Block(const float t, const float l, const float b, const float r, const Color c = Colors::White);

	Block(const float t, const float l, const Color c = Colors::White);

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

