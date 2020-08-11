#include "Block.h"

Block::Block(float t, float l, float r, float b, int rd, int grn, int bl)
	: rect(t, l, r, b, rd, grn, bl) {}

Block::Block(float t, float l, float r, float b, Color c)
	: rect(t, l, r, b, c) {}