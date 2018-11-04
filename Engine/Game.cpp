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
#include "Tile.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
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

	
	if (MoveAllowed == true)
	{
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			PosX -= 20;
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			PosX += 20;
		}
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			PosY -= 20;
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			PosY += 20;
		}
		MoveAllowed = false;
		MoveClock = 0;
	}
	if (MoveClock == MoveTimer)
	{
		MoveAllowed = true;
	}

	MoveClock += 1;
	FlashTime += 1;
	if (FlashTime == FlashClock)
	{
		Flash = false;
	}
	else if(FlashTime == FlashClock * 2)
	{
		Flash = true;
		FlashTime = 0;
	}
	
}

void Game::ComposeFrame()
{
	Tile::CorRDPipe(x, y, gfx);
	Tile::TDownPipe(x + 40, y, gfx);
	Tile::FourWayPipe(x + 40, y + 40, gfx);
	Tile::TUpPipe(x + 40, y + 80, gfx);
	Tile::TRightPipe(x, y + 40, gfx);
	Tile::TLeftPipe(x + 80, y + 40, gfx);
	Tile::CorLDPipe(x + 80, y, gfx);
	Tile::CorRUPipe(x, y + 80, gfx);
	Tile::CorLUPipe(x + 80, y + 80, gfx);
	Tile::HorzPipe(x + 20, y, gfx);
	Tile::HorzPipe(x + 60, y, gfx);
	Tile::HorzPipe(x + 20, y + 40, gfx);
	Tile::HorzPipe(x + 60, y + 40, gfx);
	Tile::HorzPipe(x + 20, y + 80, gfx);
	Tile::HorzPipe(x + 60, y + 80, gfx);
	Tile::VertPipe(x, y + 20, gfx);
	Tile::VertPipe(x, y + 60, gfx);
	Tile::VertPipe(x + 40, y + 20, gfx);
	Tile::VertPipe(x + 40, y + 60, gfx);
	Tile::VertPipe(x + 80, y + 20, gfx);
	Tile::VertPipe(x + 80, y + 60, gfx);

	if (Flash == true)
	{
		Tile::DrawSquare(PosX, PosY, gfx);
	}
}
