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
		Tile() = default;
		bool containsPoint();
		const Vec2& GetPoint() const;
		Vec2& SetPoint(const Vec2& point);

	private:
		float width;
		float height;
		bool hasPoint = false;
		Vec2 pointAt;
		Vec2 Pos;
	};


public:
	bool CheckNeighbourPoints(const Vei2& GridPos);
	Vec2 GetNewPosition(const Vec2& GridPos);
	Vec2 PosToGrid(const Vec2& Pos);

private:
	static constexpr int width = 10;
	static constexpr int height = 10;
	static constexpr int minDist = 2;
	static constexpr int newPoints = 10;
	static constexpr int k_tries = 30;
	float CellSize = minDist/sqrt(2);
	Tile field[width * height];
	const Tile& AtTile(const Vei2& gridPos) const;
	Tile& AtTile(const Vei2& gridPos);
	Vei2 GridPos;
	Vei2 ActiveList;
};