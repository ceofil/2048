#pragma once
#include "Graphics.h"
#include "Text.h"

class Board
{
public:
	Board(Graphics & gfx, Text& txt, int xboard_in, int yboard_in, int cellWidth_in, int cellHeight_in);
	void DrawCell(int x, int y, Color c);
	void DrawGrid(int thick, Color c);
	void DrawNR(Text& txt, Color c);
public:
	static constexpr int textratio = 25; //a digit its 4 cells wide + 1 cell spacing so 25 text cells allows 5 digits per board cell 
private:
	class Numbers
	{
	public:
		Color cl;
		int value = 0;
	};
private:
	int xboard;
	int yboard;
	int cellWidth;
	int cellHeight;
	static constexpr int nrow = 2;
	static constexpr int ncol = 4;
	Graphics& gfx;
	Text& txt;
	Numbers numbers[nrow][ncol];
};