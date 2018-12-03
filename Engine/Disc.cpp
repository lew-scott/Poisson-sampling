#include "Disc.h"
#include <algorithm>
#include <cmath>
#include <random>
#include "Graphics.h"




Disc::Disc(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Disc::RunDiscSeperation()
{
	SetFirstPoint();
	int i = 0; // safety catch 
	GetNewPosition();
	
}

void Disc::SetFirstPoint()
{
	Vec2 Pos;
	Vei2 gridpos;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> xDist(0, width * CellSize);
	std::uniform_real_distribution<float> yDist(0, height * CellSize);
	
	Pos = { xDist(rng), yDist(rng) };
	gridpos = PosToGrid(Pos);
	AtTile(gridpos).SetPoint(Pos);
	ActiveList.push_back(Pos);
}

bool Disc::CheckNeighbourPoints(const Vei2 & GridPos, const Vec2& TempPos)
{
	const int xStart = std::max(0, GridPos.x - 1);
	const int yStart = std::max(0, GridPos.y - 1);
	const int xEnd = std::min(width - 1, GridPos.x + 1);
	const int yEnd = std::min(height - 1, GridPos.y + 1);

	bool PointOkay = true;

	for (Vei2 cell = { xStart,yStart }; cell.y <= yEnd; cell.y++)
	{
		for (cell.x = xStart; cell.x <= xEnd; cell.x++)
		{
			if (GridPos.x != cell.x && GridPos.y != cell.y) // check not cell being checked
			{
				if (AtTile({ cell.x,cell.y }).containsPoint() == true)
				{
					Vec2 TestLenght = AtTile({ cell.x, cell.y }).GetPoint() - TempPos;
					
					if (TestLenght.GetLengthSq() < minDist * minDist)
					{
						PointOkay = false;
					}
				}
			}
		}
	}
	return PointOkay;
}

void Disc::GetNewPosition()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> xDist(0, 1);
	std::uniform_int_distribution<int> element(0, int(ActiveList.size() - 1));

	
	int i = element(rng);
	PointToBeDeleted = i;
	Vec2 oldPos = ActiveList[i];
	Vec2 newPos = {-1,-1};
	Vei2 Cell = PosToGrid(oldPos);
	
	float angle;
	bool PointOkay = true;
	int k = 0;

	while ((newPos.x < 0 || newPos.y < 0
		|| newPos.x > width * CellSize
		|| newPos.y > height * CellSize || k < k_tries))
	{
		angle = CalcAngle(0.0f, 360.0f); // returns in rads, not degrees
		float r1 = xDist(rng);
		float radius = minDist * (1 + r1);
		newPos = { oldPos.x + radius * cos(angle), oldPos.y + radius * sin(angle) };

		GridPos = PosToGrid(newPos);
		if (AtTile(GridPos).containsPoint() == false)
		{

			const int xStart = std::max(0, GridPos.x - 1);
			const int yStart = std::max(0, GridPos.y - 1);
			const int xEnd = std::min(width - 1, GridPos.x + 1);
			const int yEnd = std::min(height - 1, GridPos.y + 1);

			bool PointOkay = true;

			for (Vei2 cell = { xStart,yStart }; cell.y <= yEnd; cell.y++)
			{
				for (cell.x = xStart; cell.x <= xEnd; cell.x++)
				{
					if (GridPos.x != cell.x && GridPos.y != cell.y) // check not cell being checked
					{
						if (AtTile({ cell }).containsPoint() == true)
						{
							Vec2 TestLenght = AtTile({ cell.x, cell.y }).GetPoint() - newPos;

							if (TestLenght.GetLength() <= minDist)
							{
								PointOkay = false;
							}
						}
					}
				}
			}
		}

	if(PointOkay == true)
	{
		ActiveList.push_back(newPos);
		AtTile(GridPos).SetPoint(newPos);
		ActiveList.erase(ActiveList.begin() + PointToBeDeleted);
	}
		k++;
	}
}

Vei2 Disc::PosToGrid(const Vec2 & Pos)
{
	Vei2 GridPos = { 0,0 };
	GridPos.x = int(Pos.x / CellSize);
	GridPos.y = int(Pos.y / CellSize);

	return GridPos;
}

void Disc::DrawGrid()
{
	for (GridPos.y = 0; GridPos.y < height; GridPos.y++)
	{
		for (GridPos.x = 0; GridPos.x < width; GridPos.x++)
		{
			AtTile(GridPos).drawCell(GridPos, gfx, TopLeft);
			AtTile(GridPos).drawPoint(gfx, TopLeft);
		}
	}
}

int Disc::GetMinDisc()
{
	return minDist;
}

float Disc::CalcAngle(float x, float y)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> Dist(x, y);

	float rand = Dist(rng);
	float angle = 2 * 3.1415f * rand * 0.0174533f; // 1 deg = 0.0174533 Rad

	return angle;
}

bool Disc::GridFull()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			bool HasPoint = AtTile({ x,y }).containsPoint();

			if (HasPoint == false)
			{
				return false;
			}
		}
	}
	return true;
}


const Disc::Tile& Disc::AtTile(const Vei2 & gridPos) const
{
	return field[gridPos.y * width + gridPos.x];
}

Disc::Tile& Disc::AtTile(const Vei2 & gridPos)
{
	return field[gridPos.y * width + gridPos.x];
}



bool Disc::Tile::containsPoint()
{
	return hasPoint;
}

const Vec2& Disc::Tile::GetPoint() const
{
	return Pos;
}

Vec2 & Disc::Tile::SetPoint(const Vec2& point)
{
	hasPoint = true;
	return Pos = point;
}

void Disc::Tile::drawCell(const Vei2& gridPos, Graphics& gfx, const Vei2& offset)
{
	gfx.DrawBoxDim(int(offset.x + gridPos.x * CellSize), int(offset.y + gridPos.y * CellSize), int(CellSize), int(CellSize), { 50,50,50 });
}

void Disc::Tile::drawPoint(Graphics & gfx, const Vei2& offset)
{
	if (hasPoint == true)
	{

		gfx.DrawCircleWithPoint(int(offset.x + Pos.x), int(offset.y + Pos.y), 18, { 200,0,200 });
	}
}
