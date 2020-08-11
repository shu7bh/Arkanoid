#include "Player.h"

Player::Player(float t, float l, float r, float b, int rd, int grn, int bl)
	: block(t, l, r, b, rd, grn, bl), v(0) {}