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
		void SetPoint(const Vec2& point);
		void SetState(bool state);
		void drawCell(const Vei2& gridPos, Graphics& gfx, const Vei2& offset);
		void drawPoint(Graphics& gfx, const Vei2& offset);

	private:
		float CellSize = minDist / float(sqrt(2));
		bool hasPoint = false;
		bool Active = true;
		Vec2 pointAt;
		Vec2 Pos;
		
	};
public:
	Disc(Graphics& gfx);

public:
	void SetFirstPoint();
	void GetNewPosition();
	Vei2 PosToGrid(const Vec2& Pos);
	void DrawGrid();
	int GetMinDisc();

	float CalcAngle(float x, float y);
	bool GridFull();

private:
	static constexpr int width = 48;
	static constexpr int height = 36;
	static constexpr int minDist = 20;
	// alter k-tries to increase or decrease total number of point on the grid
	static constexpr int k_tries = 50;
	int PointToBeDeleted = -1;

	float CellSize = minDist/float(sqrt(2));
	Tile field[width * height];
	const Tile& AtTile(const Vei2& gridPos) const;
	Tile& AtTile(const Vei2& gridPos);
	Vei2 GridPos;
	std::vector<Vec2> ActiveList;
	std::vector<Vec2> PointList;
	Vei2 TopLeft = { 60,50 };
	Graphics& gfx;
};