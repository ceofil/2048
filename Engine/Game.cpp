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
#include <cmath>
#include <random>
#include <chrono>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xrange(0, gfx.ScreenWidth - 30),
	text(gfx, 100, 100, txtrez, txtrez, 50, 7),
	brd(gfx,text,100,100,cellsize,cellsize)
{	
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
	

	brd.Update(wnd.kbd);
}



void Game::ComposeFrame()
{

	brd.DrawNR(text, Colors::White);
	brd.DrawGrid(5, Colors::White);
	if (brd.gameover) {
		gfx.DrawCircle(400, 300, 100, Colors::Red);
	}
}




