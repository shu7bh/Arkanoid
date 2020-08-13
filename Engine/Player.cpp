#include "Player.h"
#include "MainWindow.h"

Player::Player(const float t, const float l, const float r, const float b, const int rd, const int grn, const int bl)
	: rect(t, l, r, b, rd, grn, bl), v(0) {}

Player::Player(const float t, const float l, const float r, const float b, const Color c)
	: rect(t, l, r, b, c), v(0) {}

Player::Player(const float t, const float l, const Color c)
	: rect(t, l, height, width, c), v(0) {}

void Player::update()
{
	rect.update(v, 0);
}

void Player::ChangeVelocity(MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT) || wnd.kbd.KeyIsPressed('A'))
	{
		v = (v >= 0) ? -3.5f : v;
		v += (v <= -5) ? 0 : -0.05f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT) || wnd.kbd.KeyIsPressed('D'))
	{
		v = (v <= 0) ? 3.5f : v;
		v += (v >= 5) ? 0 : +0.05f;
	}
	else v = 0;
}

void Player::KeepInFrame(int Left, int Right)
{
	if (int(rect.left) <= Left - int(v) || int(rect.right) >= Right - int(v))
		v = 0;
}
