#include "Disc.h"
#include <algorithm>
#include <cmath>
#include <random>




bool Disc::CheckNeighbourPoints(const Vei2 & GridPos)
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
			if (GridPos.x == cell.x && GridPos.y == cell.y) // check not cell being checked
			{

			}
			else
			{
				if (AtTile({ cell.x,cell.y }).containsPoint() == true)
				{
					Vec2 vec1 = AtTile(GridPos).GetPoint();
					Vec2 vec2 = AtTile({ cell.x, cell.y }).GetPoint();
					Vec2 newVec = vec1 - vec2;
					if (newVec.GetLengthSq() < minDist * minDist)
					{
						PointOkay = false;
					}

				}
			}
			
		}
	}
	return PointOkay;
}

Vec2 Disc::GetNewPosition(const Vec2 & GridPos)
{
	Vec2 newPos;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> xDist(0, 1);
	float r1 = xDist(rng);
	float r2 = xDist(rng);

	float radius = minDist * (1 + r1);
	float angle = 2 * 3.1415 * r2;

	float newX = GridPos.x + radius * cos(angle);
	float newY = GridPos.y + radius * sin(angle);

	return newPos = { newX,newY };
}

Vec2 Disc::PosToGrid(const Vec2 & Pos)
{
		Vec2 GridPos = { Pos.x / CellSize,
					     Pos.y / CellSize };

	return GridPos;
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
	return pointAt;
}

Vec2 & Disc::Tile::SetPoint(const Vec2& point)
{
	hasPoint = true;
	return pointAt = point;
}
