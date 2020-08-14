#include "Player.h"
#include "MainWindow.h"

Player::Player(const float t, const float l, const float r, const float b, const int rd, const int grn, const int bl)
	: rect(t, l, r, b, rd, grn, bl), v(0) {}

Player::Player(const float t, const float l, const float r, const float b, const Color c)
	: rect(t, l, r, b, c), v(0) {}

Player::Player(const float t, const float l, const Color c)
	: rect(t, l, height, width, c), v(0) {}


void Player::update(const float dt)
{
	rect.update(v * dt, 0);
}

void Player::ChangeVelocity(MainWindow& wnd)
{
	if (wnd.mouse.GetPosX() < rect.left)
	{
		v = (v >= 0) ? -3.5f * 60.0f : v;
		v += (v <= -5 * 60.0f) ? 0 : -0.05f * 60.0f;
	}

	else if (wnd.mouse.GetPosX() > rect.right)
	{
		v = (v <= 0) ? 3.5f * 60.0f : v;
		v += (v >= 5 * 60.0f) ? 0 : +0.05f * 60.0f;
	}
	else
		v = 0;

//if (wnd.kbd.KeyIsPressed(VK_LEFT) || wnd.kbd.KeyIsPressed('A'))
//	{
//		v = (v >= 0) ? -3.5f * 60.0f : v;
//		v += (v <= -5 * 60.0f) ? 0 : -0.05f * 60.0f;
//	}
//
//	
//	else if (wnd.kbd.KeyIsPressed(VK_RIGHT) || wnd.kbd.KeyIsPressed('D'))
//	{
//		v = (v <= 0) ? 3.5f * 60.0f : v;
//		v += (v >= 5 * 60.0f) ? 0 : +0.05f * 60.0f;
//	}
//	else v = 0;
}

void Player::KeepInFrame(int Left, int Right)
{	
	if (int(rect.left) <= Left)
		v = 0, rect.left = float(Left), rect.right = rect.left + width;
		
	if (int(rect.right) >= Right)
		v = 0, rect.right = float(Right - 1), rect.left = rect.right - width;
}
