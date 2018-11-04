#pragma once
#include "Graphics.h"

class Tile
{
public:
	static void VertPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx);
	static void HorzPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx);
	static void CorRDPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx);
	static void CorLDPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx);
	static void CorRUPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx);
	static void CorLUPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx);
	static void TRightPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx);
	static void TLeftPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx);
	static void TUpPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx);
	static void TDownPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx);
	static void FourWayPipe(int ScreenPosX, int ScreenPosY, Graphics& gfx);
	static void DrawSquare(int ScreenPosX, int ScreenPosY, Graphics& gfx);

};