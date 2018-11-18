#include "Disc.h"
#include <algorithm>




void Disc::NeighbourTiles(const Vei2 & GridPos)
{
	const int xStart = std::max(0, GridPos.x - 1);
	const int yStart = std::max(0, GridPos.y - 1);
	const int xEnd = std::min(width - 1, GridPos.x + 1);
	const int yEnd = std::min(height - 1, GridPos.y + 1);

	bool PointOkay = true;

	for (Vei2 gridPos = { xStart,yStart }; gridPos.y <= yEnd; gridPos.y++)
	{
		for (gridPos.x = xStart; gridPos.x <= xEnd; gridPos.x++)
		{
			if (gridPos.x == xStart && gridPos.y == yStart) // check not cell being checked
			{

			}
			else
			{
				AtTile({ xStart,yStart }).containsPoint();
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
