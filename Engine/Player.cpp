#include "Player.h"

Player::Player(float t, float l, float b, float r, int rd, int grn, int bl)
	: rect(t, l, b, r, rd, grn, bl), v(0) {}

Player::Player(float t, float l, float b, float r, Color c)
	: rect(t, l, b, r, c), v(0) {}