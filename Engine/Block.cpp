#include "Block.h"

Block::Block(float t, float l, float b, float r, int rd, int grn, int bl)
	: rect(t, l, r, b, rd, grn, bl) {}

Block::Block(float t, float l, float b, float r,Color c)
	: rect(t, l, r, b, c) {}