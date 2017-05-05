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
	void newGame();
public:
	static constexpr int textratio = 25; //a digit its 4 cells wide + 1 cell spacing so 25 text cells allows 5 digits per board cell 
	bool cooldown = false;
	bool gameover = false;
	int score = 0;
	int highscore = 0;
	static constexpr int colors[15][3] = {
		{ 165,165,165 }, //0
		{ 205, 200, 190 }, //2
		{ 190, 180, 170 }, //4
		{ 235, 160, 118 }, //8
		{ 240, 126, 67 }, //16
		{ 245, 92, 0 }, //32
		{ 255, 77, 77 }, //64
		{ 227, 227, 90 }, //128
		{ 231, 231, 86 }, //256
		{ 235, 235, 82 }, //512
		{210,180,50 }, //1024
		{210,160,30}, //2048
		{110,240,110}, //4056
		{110,110,255}  //8112
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