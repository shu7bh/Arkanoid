#include "Ball.h"

int Ball::score = 0;

//ball constructor definition, with left and right 
Ball::Ball(const float t, const float l, const float b, const float r, const Color c)
	: rect(t, l, b, r, c) 
{
	vx = 0, vy = 1;
}

//ball constructor definition, without left and right 
Ball::Ball(const float t, const float l, const Color c)
	: rect(t, l, width, width, c)
{
	vx = 0, vy = 1;
}

#define B(x) ball.getRect().x

Ball::Ball(const Ball& ball)
{
	rect.top = B(top), rect.bottom = B(bottom), rect.left = B(left), rect.right = B(right);
	rect.color = B(color);
	vx = ball.vx * 1.5f, vy = ball.vy / 2;
}

#undef B
//ball movement definition
void Ball::update(const float dt, const float totalTime)
{
	float addSpeed = (vy == 0) ? 0 : (vy / abs(vy)) * totalTime * 60.0f * dt / 30.0f;
	rect.update(vx * dt , vy * dt + addSpeed);
}

//function that ensures ball remains in frame, but allows it to escape through bottom. hence bottom is not taken
//note that rect here refers to the ball
void Ball::keepInFrame(int top, int left, int right)
{
	if (int(rect.top) < top) // if ball goes above the top limit of game
	{
		rect.top = float(top);				//ensures the ball maintains the shape (top)
		rect.bottom = float(top + width);	//ensures the ball maintains the shape (bottom)
		vy = -vy;							//the ball now changes 
	}

	if (int(rect.left) < left)				//similar to the previous one
	{
		rect.left = float(left);
		rect.right = float(left + width);
		vx = -vx;
	}

	if (int(rect.right) >= right)			//similar to the previous one
	{
		rect.right = float(right - 1);		//we subtract 1 here becoz previously the ball goes 1 above the right boundary?
		rect.left = rect.right - float(width);
		vx = -vx;
	}
}

//if the ball passes through the bottom boundary
bool Ball::touchedBottom(int bottom)
{
	if (int(rect.bottom >= bottom))
		return true;
	return false;
}

//the ball hits the block. function takes in position of the block which is hit 
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
		if (vx <= 0 && vy < 0) // coming from the bottom right
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
			vx = -vx / 2; // coming from bottom left
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
		else if (vx >= 0 && vy < 0)
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

#include <random>
void Ball::hitPlayer(const Rect& player, const float dt)
{
	static std::random_device rd;
	static std::default_random_engine generator(rd());
	static std::uniform_real_distribution<float> values(2.0f, 3.5f);
	static std::uniform_int_distribution<int> detDir(-1, 1);
	
	if (rect.bottom >= player.top &&
		rect.left > player.left &&
		rect.right < player.right)
	{
		rect.update(-vx * dt, -vy * dt);
		vx = float(detDir(generator)) * values(generator) * 60.0f, vy = -values(generator) * 60.0f;
	}
	else if ((rect.bottom >= player.top &&
		rect.right >= player.left &&
		rect.bottom <= player.bottom && // top left
		rect.right <= player.right) 
					|| 
		(rect.bottom >= player.top &&
		rect.left >= player.left &&
		rect.bottom <= player.bottom && // top right
		rect.left <= player.right))
	{
		rect.update(-vx * dt, -vy * dt);
		vx = -vx, vy = -vy;
	}
}
