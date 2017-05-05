#pragma once
#include "Graphics.h"
#include "Text.h"
#include "Keyboard.h"
#include <random>

class Board
{
public:
	Board(Graphics & gfx, Text& txt, int xboard_in, int yboard_in, int cellWidth_in, int cellHeight_in);
	void Update(Keyboard& kbd);
	void DrawCell(int x, int y, Color c);
	void DrawGrid(int thick, Color c);
	void DrawNR(Text& txt, Color c);
	bool CheckRow(int i);
	bool CheckCol(int j);
	void spawnOnRow(int i);
	void spawnOnCol(int j);
public:
	static constexpr int textratio = 25; //a digit its 4 cells wide + 1 cell spacing so 25 text cells allows 5 digits per board cell 
	bool cooldown = false;
	static constexpr int colors[15][3] = {
		{ 145,145,145 }, //0
		{ 215, 210, 200 }, //2
		{ 200, 190, 180 }, //4
		{ 245, 170, 128 }, //8
		{ 250, 136, 77 }, //16
		{ 255, 102, 0 }, //32
		{ 255, 77, 77 }, //64
		{ 247, 247, 110 }, //128
		{ 251, 251, 106 }, //256
		{ 255, 255, 102 } //512

	};
private:
	class Numbers
	{
	public:
		Color cl;
		int clr=0;
		
		int value = 0;
	};
private:
	int xboard;
	int yboard;
	int cellWidth;
	int cellHeight;
	static constexpr int nrow = 4;  //the number of rows, not the number of cells per row
	static constexpr int ncol = 4;  //same
	Graphics& gfx;
	Text& txt;
	Numbers numbers[nrow][ncol];
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> rowrange; 
	std::uniform_int_distribution<int> colrange;
};