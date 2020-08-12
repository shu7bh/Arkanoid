#include "Player.h"
#include "MainWindow.h"

Player::Player(float t, float l, float r, float b, int rd, int grn, int bl)
	: rect(t, l, r, b, rd, grn, bl), v(0) {}

Player::Player(float t, float l, float r, float b, Color c)
	: rect(t, l, r, b, c), v(0) {}

void Player::update()
{
	rect.update(v, 0);
}

void Player::ChangeVelocity(MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT) || wnd.kbd.KeyIsPressed('A'))
	{
		v = (v >= 0) ? -3.5 : v;
		v += (v <= -5) ? 0 : -0.05f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT) || wnd.kbd.KeyIsPressed('D'))
	{
		v = (v <= 0) ? +3.5 : v;
		v += (v >= 5) ? 0 : +0.05f;
	}
	else v = 0;
}

void Player::KeepInFrame(int Left, int Right)
{
	if (int(rect.left) <= Left - int(v) || int(rect.right) >= Right - int(v))
		v = 0;
}
