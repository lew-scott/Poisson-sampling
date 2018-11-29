#pragma once
#include<cmath>
#include<utility>
#include "Vei2.h"
#include "Vec2.h"
#include <vector>
#include "Graphics.h"


class Disc
{
	class Tile
	{
	public:
		Tile() = default;
		bool containsPoint();
		const Vec2& GetPoint() const;
		Vec2& SetPoint(const Vec2& point);
		void drawCell(const Vei2& gridPos, Graphics& gfx, const Vei2& offset);
		void drawPoint(Graphics& gfx, const Vei2& offset);

	private:
		float CellSize = minDist / float(sqrt(2));
		bool hasPoint = false;
		Vec2 pointAt;
		Vec2 Pos;
		
	};
public:
	Disc(Graphics& gfx);

public:
	void RunDiscSeperation();
	void SetFirstPoint();
	bool CheckNeighbourPoints(const Vei2& GridPos, const Vec2& TempPos);
	Vec2 GetNewPosition();
	Vei2 PosToGrid(const Vec2& Pos);
	void DrawGrid();
	int GetMinDisc();
	float CalcAngle(float x, float y);

private:
	static constexpr int width = 10;
	static constexpr int height = 10;
	static constexpr int minDist = 50;
	static constexpr int newPoints = 10;
	static constexpr int k_tries = 30;
	float CellSize = minDist/float(sqrt(2));
	Tile field[width * height];
	const Tile& AtTile(const Vei2& gridPos) const;
	Tile& AtTile(const Vei2& gridPos);
	Vei2 GridPos;
	std::vector<Vec2> ActiveList;
	std::vector<Vec2> PointList;
	Vei2 TopLeft = { 50,50 };
	Graphics& gfx;
};