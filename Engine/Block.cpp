#include "Block.h"

std::default_random_engine Block::generator((unsigned int)time(0));
std::uniform_int_distribution<int> Block::values(1, 5);

const std::vector<Color> Block::colors = 
	{ Colors::Black, Colors::Blue, Colors::Green, Colors::Magenta, Colors::Cyan, Colors::Red };

Block::Block(const float t, const float l, const float b, const float r, const int rd, const int grn, const int bl)
	: rect(t, l, b, r, rd, grn, bl), hitCounter(values(generator)) 
{
	rect.color = colors[hitCounter];
}

Block::Block(const float t, const float l, const float b, const float r, Color c)
	: rect(t, l, b, r, c), hitCounter(values(generator)) 
{
	rect.color = colors[hitCounter];
}

Block::Block(const float t, const float l, const Color c)
	: rect(t, l, height, width, c)
{
}
