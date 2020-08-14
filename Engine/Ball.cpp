#include "Ball.h"
//ball constructor definition, with 
Ball::Ball(const float t, const float l, const float b, const float r, const Color c)
	: rect(t, l, b, r, c) 
{
	vx = 1.5f * 60.0f;
	vy = 1.5f * 60.0f;
}

Ball::Ball(const float t, const float l, const Color c)
	: rect(t, l, width, width, c)
{
	vx = 1.5f * 60.0f;
	vy = 1.5f * 60.0f;
}

//ball movement definition
void Ball::update(const float dt)
{
	rect.update(vx * dt, vy * dt);
}

void Ball::keepInFrame(int top, int left, int right)
{
	if (int(rect.top) < top)
	{
		rect.top = float(top);
		rect.bottom = float(top + width);
		vy = -vy;
	}

	if (int(rect.left) < left)
	{
		rect.left = float(left);
		rect.right = float(left + width);
		vx = -vx;
	}

	if (int(rect.right) >= right)
	{
		rect.right = float(right - 1);
		rect.left = rect.right - float(width);
		vx = -vx;
	}
}

bool Ball::touchedBottom(int bottom)
{
	if (int(rect.bottom >= bottom))
		return true;
	return false;
}

bool Ball::hitBlock(const Rect& block, const float dt)
{
	if (rect.bottom >= block.top &&
		rect.bottom < block.bottom &&
		rect.left > block.left &&
		rect.right < block.right)
	{ // If condition if the ball touches the bottom side only, not the corners at all (for the ball)
		rect.bottom = block.top;
		rect.top = rect.bottom - width;
		vy = -vy;
		return true;
	}

	if (rect.top > block.top &&
		rect.top <= block.bottom &&
		rect.left > block.left &&
		rect.right < block.right)
	{ // If condition if the ball touches the top side only, not the corners at all (for the ball)
		rect.top = block.bottom;
		rect.bottom = rect.top + width;
		vy = -vy;
		return true;
	}

	if (rect.left > block.left &&
		rect.left <= block.right &&
		rect.top > block.top &&
		rect.bottom < block.bottom)
	{ // If condition if the ball touches the Left side only, not the corners at all (for the ball)
		rect.left = block.right;
		rect.right = rect.left + width;
		vx = -vx;
		return true;
	}

	if (rect.right >= block.left &&
		rect.right < block.right &&
		rect.top > block.top &&
		rect.bottom < block.bottom)
	{ // If condition if the ball touches the right side only, not the corners at all (for the ball)
		rect.right = block.left;
		rect.left = rect.right - width;
		vx = -vx;
		return true;
	}
// block ball corner interface

/*
	if ((rect.bottom >= block.top &&
		rect.left >= block.left &&
		rect.bottom <= block.bottom && // top right
		rect.left <= block.right)
		||
		(rect.top >= block.top &&
		rect.left >= block.left &&
		rect.top <= block.bottom && // bottom right
		rect.left <= block.right
		)
		||
		(rect.bottom >= block.top &&
		rect.right >= block.left &&
		rect.bottom <= block.bottom && // top left
		rect.right <= block.right)
		||
		(rect.top >= block.top &&
		rect.right >= block.left &&
		rect.top <= block.bottom && // bottom left
		rect.right <= block.right
		))
	{
		vy = -vy;
		vx = -vx;
		return true;
	}

*/
	if (rect.bottom >= block.top &&
		rect.left >= block.left &&
		rect.bottom <= block.bottom && // top right
		rect.left <= block.right) 
	{
		rect.update(-vx * dt, -vy * dt);
		if (vx < 0 && vy < 0) // coming from the bottom right
			vx = -vx / 2;
		else if (vx > 0 && vy > 0)
			vy = -vy / 2; // top left coming towards top right
		else if (vx < 0 && vy > 0)
			vx = -vx, vy = -vy; // top right towards top right
		return true;

		// before: it goes inside the block, 
	}

	if (rect.top >= block.top &&
		rect.left >= block.left &&
		rect.top <= block.bottom && // bottom right
		rect.left <= block.right)
	{
		rect.update(-vx * dt, -vy * dt);
		if (vx < 0 && vy < 0) // coming from the bottom right
			vx = -vx, vy = -vy;
		else if (vx < 0 && vy > 0)
			vx = -vx / 2; // coming from top right
		else if (vx > 0 && vy < 0)
			vy = -vy / 2; // coming from bottom left
		return true;
	}

	if(rect.bottom >= block.top &&
		rect.right >= block.left &&
		rect.bottom <= block.bottom && // top left
		rect.right <= block.right)
	{
		rect.update(-vx * dt, -vy * dt);
		if (vx > 0 && vy > 0) // coming from top left
			vx = -vx, vy = -vy;
		else if (vx < 0 && vy > 0)
			vy = -vy / 2; // coming from top right
		else if (vx > 0 && vy < 0)
			vx = -vx, vy = -vy; // coming from bottom right
		return true;		
	}

	if (rect.top >= block.top &&
		rect.right >= block.left &&
		rect.top <= block.bottom && // bottom left
		rect.right <= block.right
		)
	{
		rect.update(-vx * dt, -vy * dt);
		if (vx < 0 && vy < 0) // coming from the bottom right
			vy = -vy / 2;
		else if (vx > 0 && vy > 0)
			vx = -vx / 2; // coming from top left
		else if (vx > 0 && vy < 0)
			vy = -vy , vx = -vx; // coming from bottom left
		return true;
	}
	return false;
}

void Ball::draw(Graphics& gfx) const
{
	int rad = int((rect.right - rect.left) / 2);
	int cx = int((rect.right + rect.left) / 2);
	int cy = int((rect.bottom + rect.top) / 2);

	for (int i = int(rect.left); i <= int(rect.right); ++i)
		for (int j = int(rect.top); j <= int(rect.bottom); ++j)
			if ((cx - i) * (cx - i) + (cy - j) * (cy - j) <= rad * rad)
				gfx.PutPixel(i, j, rect.color);
}

bool Ball::hitPlayer(const Rect& player)
{
	if (rect.bottom >= player.top &&
		rect.bottom < player.bottom &&
		rect.left > player.left &&
		rect.right < player.right)
	{ // If condition if the ball touches the bottom side only, not the corners at all
		vy = -vy;
		return true;
	}

	if (rect.top > player.top &&
		rect.top <= player.bottom &&
		rect.left > player.left &&
		rect.right < player.right)
	{ // If condition if the ball touches the top side only, not the corners at all
		vy = -vy;
		return true;
	}

	if (rect.left >= player.left &&
		rect.left < player.right &&
		rect.top > player.top &&
		rect.bottom < player.bottom)
	{ // If condition if the ball touches the Left side only, not the corners at all
		vx = -vx;
		return true;
	}

	if (rect.right > player.left &&
		rect.right <= player.right &&
		rect.top > player.top &&
		rect.bottom < player.bottom)
	{ // If condition if the ball touches the right side only, not the corners at all
		vx = -vx;
		return true;
	}

	if ((rect.bottom >= player.top &&
		rect.left >= player.left &&
		rect.bottom <= player.bottom &&
		rect.left <= player.right)
		||
		(rect.top >= player.top &&
			rect.left >= player.left &&
			rect.top <= player.bottom &&
			rect.left <= player.right
			)
		||
		(rect.bottom >= player.top &&
			rect.right >= player.left &&
			rect.bottom <= player.bottom &&
			rect.right <= player.right)
		||
		(rect.top >= player.top &&
			rect.right >= player.left &&
			rect.top <= player.bottom &&
			rect.right <= player.right
			))
	{
		vy = -vy;
		vx = -vx;
		return true;
	}
	return false;
}
