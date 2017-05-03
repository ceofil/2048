#pragma once
#include "Graphics.h"
#include <cstring>

class Board
{
public:
	Board(Graphics & gfx, int xboard_in, int yboard_in, int cellWidth_in, int cellHeight_in, int row_nrcells, int col_nrcells);
	void DrawCell(int x, int y, Color c);
	void DrawGrid(int thick, Color c);
private:
	int xboard;
	int yboard;
	int cellWidth;
	int cellHeight;
	int nrow;
	int ncol;
	Graphics& gfx;
};