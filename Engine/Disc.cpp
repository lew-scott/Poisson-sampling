#include "Disc.h"
#include <algorithm>




void Disc::NeighbourTiles(const Vei2 & GridPos)
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

}

const Disc::Tile& Disc::AtTile(const Vei2 & gridPos) const
{
	return field[gridPos.y * width + gridPos.x];
}

Disc::Tile& Disc::AtTile(const Vei2 & gridPos)
{
	return field[gridPos.y * width + gridPos.x];
}

Disc::Tile::Tile(float width, float height)
	:
	width(width),
	height(height)
{
}

bool Disc::Tile::containsPoint()
{
	return hasPoint;
}

const Vec2& Disc::Tile::GetPoint() const
{
	return pointAt;
}
