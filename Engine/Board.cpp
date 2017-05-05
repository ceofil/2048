#include "Board.h"

Board::Board(Graphics & gfx, Text& txt, int xboard_in, int yboard_in, int cellWidth_in, int cellHeight_in)
	:
	gfx(gfx),
	txt(txt),
	xboard(xboard_in),
	yboard(yboard_in),
	cellWidth(cellWidth_in),
	cellHeight(cellHeight_in),
	rng(rd()),
	rowrange(0, nrow-1),
	colrange(0, ncol-1)
{
	for (int i = 0; i < nrow; i++) {
		for (int j = 0; j < ncol; j++) {
			numbers[i][j].value = 0;
		}
	}
	numbers[1][1].value = 16;
}
void Board::Update(Keyboard & kbd)
{

	if (cooldown) {
		cooldown = kbd.KeyIsPressed(VK_UP) || kbd.KeyIsPressed(VK_DOWN) || kbd.KeyIsPressed(VK_LEFT) || kbd.KeyIsPressed(VK_RIGHT);
	}
	if (kbd.KeyIsPressed(VK_UP)) {
		if (!cooldown) {
			bool test = false;
			cooldown = true;
			for (int i = nrow - 1; i >= 0; i--) {
				if (CheckRow(i)) {
					spawnOnRow(i);
					test = true;
					break;
				}
			}
		}
	}
	else if (kbd.KeyIsPressed(VK_DOWN)) {
		if (!cooldown) {
			bool test = false;
			cooldown = true;
			for (int i = 0; i < nrow; i++) {
				if (CheckRow(i)) {
					spawnOnRow(i);
					test = true;
					break;
				}
			}
		}
	}
	else if (kbd.KeyIsPressed(VK_LEFT)) {
		if (!cooldown) {
			bool test = false;
			cooldown = true;
			for (int j = ncol - 1; j >= 0; j--) {
				if (CheckCol(j)) {
					spawnOnCol(j);
					test = true;
					break;
				}
			}
		}
	}
	else if (kbd.KeyIsPressed(VK_RIGHT)) {
		if (!cooldown) {
			bool test = false;
			cooldown = true;
			for (int j = 0; j < ncol; j++) {
				if (CheckCol(j)) {
					spawnOnCol(j);
					test = true;
					break;
				}
			}
		}
	}


}
void Board::DrawCell(int x, int y, Color c)
{
	gfx.DrawRectPoints(xboard + cellWidth*x, yboard + cellHeight*y, xboard + cellWidth*(x + 1), xboard + cellHeight*(y + 1), c);

}

void Board::DrawGrid(int thick, Color c)
{
	for (int i = 0; i <= ncol; i++) {
		gfx.DrawRectPoints(xboard+i*cellWidth - thick, yboard,xboard + i*cellWidth + thick, yboard + nrow*cellHeight, c);
	}
	for (int i = 0; i <= nrow; i++) {
		gfx.DrawRectPoints(xboard, yboard + i*cellHeight - thick, xboard + ncol*cellWidth, yboard + i*cellHeight + thick, c);
	}
}

void Board::DrawNR(Text & txt, Color c)
{
	
	for (int i = 0; i < nrow; i++) {
		int ypoz = i*textratio + textratio / 2 - 3;  //-3 cuz its 4x7
		for (int j = 0; j < ncol; j++) {
			int digits = txt.nrcifre(numbers[i][j].value);
			int xpoz = j*textratio + textratio / 2 - digits*5/2+1; //same 
			txt.drawint(numbers[i][j].value, xpoz, ypoz, c);
		}
	}
}

bool Board::CheckRow(int i)
{
	bool test = false;
	for (int j = 0; j < ncol; j++) {
		test = test || (numbers[i][j].value==0);
	}
	return test;
}

bool Board::CheckCol(int j)
{
	bool test=false;
	for (int i = 0; i < nrow; i++) {
		test = test || (numbers[i][j].value==0);
	}
	return test;
}

void Board::spawnOnRow(int i)
{
	bool spawned = false;
	while (!spawned) {
		int nr = colrange(rng);
		if(numbers[i][nr].value==0){
			numbers[i][nr].value = 2;
			spawned = true;
		}
	}
}
void Board::spawnOnCol(int j)
{
	bool spawned = false;
	while (!spawned) {
		int nr = colrange(rng);
		if (numbers[nr][j].value == 0) {
			numbers[nr][j].value = 2;
			spawned = true;
		}
	}
}


