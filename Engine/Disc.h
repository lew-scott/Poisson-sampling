#pragma once
#include<cmath>
#include<utility>
#include "Vei2.h"
#include "Vec2.h"
#include <vector>


class Disc
{
	class Tile
	{
	public:
		Tile(float width, float height);
		bool containsPoint();

	private:
		float width;
		float height;
		bool hasPoint = false;
		Vec2 pointAt;
	};


public:


	void NeighbourTiles(const Vei2& GridPos);

private:

	static constexpr int width = 10;
	static constexpr int height = 10;
	static constexpr int minDist = 2;
	static constexpr int newPoints = 10;
	float CellSize = minDist / sqrt(2.0f);
	Tile field[width * height];
	const Tile& AtTile(const Vei2& gridPos) const;
	Tile& AtTile(const Vei2& gridPos);
	Vei2 GridPos;
};