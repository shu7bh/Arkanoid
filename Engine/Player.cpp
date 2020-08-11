#include "Player.h"

Player::Player(float t, float l, float r, float b, int rd, int grn, int bl)
	: rect(t, l, r, b, rd, grn, bl), v(0) {}

Player::Player(float t, float l, float r, float b, Color c)
	: rect(t, l, r, b, c), v(0) {}