#include "Tile.h"

void Tile::VertPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
}

void Tile::HorzPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx)
{
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
		for (int y = 17; y < 20; y++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
}

void Tile::CorRDPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
}

void Tile::CorLDPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
}

void Tile::CorRUPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx)
{

	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 20; x++)
	{
		for (int y = 17; y < 20; y++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 3; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
}

void Tile::CorLUPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx)
{

	for (int y = 0; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 20; x++)
	{
		for (int y = 17; y < 20; y++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
}

void Tile::TRightPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx)
{

	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int x = 17; x < 20; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
}

void Tile::TLeftPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
}

void Tile::TUpPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx)
{

	for (int y = 17; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 3; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
}

void Tile::TDownPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int x = 0; x < 3; x++)
	{
		for (int y = 17; y < 20; y++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
}

void Tile::FourWayPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int y = 0; y < 3; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
	for (int y = 17; y < 20; y++)
	{
		for (int x = 17; x < 20; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::Blue);
		}
	}
}

void Tile::DrawSquare(int ScreenPosX, int ScreenPosY, Graphics & gfx)
{ 
	for (int y = 4; y < 16; y++)
	{
		for (int x = 4; x < 16; x++)
		{
			gfx.PutPixel(ScreenPosX + x, ScreenPosY + y, Colors::White);
		}
	}
}
