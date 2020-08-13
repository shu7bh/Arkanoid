/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	player(500, 200),
	ball(gfx.ScreenHeight / 2 + 10, 10)
{
	for (auto j = 20, count = 1; j < gfx.ScreenHeight / 2; j += Block::height + 10, ++count)
		for (auto i = 10, ct = 0; i < gfx.ScreenWidth - Block::width - 10 && ct < count; i += Block::width + 10, ++ct)
		blocks.push_back(std::make_unique<Block>(float(j), float(i), float(j + Block::height), float(i + Block::width)));
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	player.ChangeVelocity(wnd);
	player.KeepInFrame(0, gfx.ScreenWidth);
	player.update();
	ball.update();
	ball.keepInFrame(0, 0, gfx.ScreenWidth);
	if (ball.hitPlayer(player.getRect()))
		ball.vx += (player.v > 0)? (ball.vx >= 3)? 0 : player.v / 3 : (ball.vx <= -3)? 0: player.v / 3;

	for (auto& block : blocks)
		if (ball.hitBlock(block->getRect()))
			block->DecHitCounter();

	for (auto i = 0; i < blocks.size(); ++i)
		if (blocks[i]->HitCounter() == 0)
		{
			blocks.erase(blocks.begin() + i);
			--i;
			break;
		}

	if (ball.touchedBottom(gfx.ScreenHeight))
		exit(0);
}

void Game::ComposeFrame()
{
	player.getRect().draw(gfx);
	for (const auto& block : blocks)
		block->getRect().draw(gfx);
	ball.draw(gfx);
}