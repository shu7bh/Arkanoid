#include "Player.h"
#include "MainWindow.h"

Player::Player(const float t, const float l, const float r, const float b, const int rd, const int grn, const int bl)
	: rect(t, l, r, b, rd, grn, bl), v(0) {}

Player::Player(const float t, const float l, const float r, const float b, const Color c)
	: rect(t, l, r, b, c), v(0) {}

Player::Player(const float t, const float l, const Color c)
	: rect(t, l, height, width, c), v(0) {}


void Player::update(const float dt, const float totalTime)
{
	float addSpeed = (v == 0) ? 0 : (v / abs(v)) * totalTime * 60.0f * dt / 30.0f;
	rect.update(v * dt + addSpeed, 0);
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

}

void Player::KeepInFrame(int Left, int Right)
{	
	if (int(rect.left) <= Left)
		v = 0, rect.left = float(Left), rect.right = rect.left + width;
		
	if (int(rect.right) >= Right)
		v = 0, rect.right = float(Right - 1), rect.left = rect.right - width;
}
