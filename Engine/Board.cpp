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
	int i1 = rowrange(rng);
	int j1 = colrange(rng);
	numbers[i1][j1].value = 2;
	numbers[i1][j1].clr = 1;
	
	i1 = rowrange(rng);
	j1 = colrange(rng);
	numbers[i1][j1].value = 2;
	numbers[i1][j1].clr = 1;
}
void Board::Update(Keyboard & kbd)
{

	if (cooldown) {
		cooldown = kbd.KeyIsPressed(VK_UP) || kbd.KeyIsPressed(VK_DOWN) || kbd.KeyIsPressed(VK_LEFT) || kbd.KeyIsPressed(VK_RIGHT);
	}
	else {
		bool test = false;
		if (kbd.KeyIsPressed(VK_UP)) {
				cooldown = true;
				for (int j = 0; j < ncol; j++) {
					int k = -1;
					for (int i = 0; i < nrow; i++) {
						if (numbers[i][j].value != 0) {
							
							std::swap(numbers[i][j], numbers[++k][j]);
						}
					}
					for (int i = 0; i < nrow - 1; i++) {
						if (numbers[i][j].value == numbers[i + 1][j].value) {
							numbers[i][j].value *= 2;
							numbers[i][j].clr++;
							numbers[i + 1][j].value = 0;
							numbers[i + 1][j].clr = 0;
						}
					}
					k = -1;
					for (int i = 0; i < nrow; i++) {
						if (numbers[i][j].value != 0) {
							
							std::swap(numbers[i][j], numbers[++k][j]);
						}
					}
				}
				for (int i = nrow - 1; i >= 0; i--) {
					if (CheckRow(i)) {
						spawnOnRow(i);
						test = true;
						break;
					}
				}
			
		}
		else if (kbd.KeyIsPressed(VK_DOWN)) {
				cooldown = true;
				////////

				for (int j = 0; j < ncol; j++) {
					int k = nrow;
					for (int i = nrow - 1; i >= 0; i--) {
						if (numbers[i][j].value != 0) {
							std::swap(numbers[i][j], numbers[--k][j]);
						}
					}
					for (int i = nrow - 1; i > 0; i--) {
						if (numbers[i][j].value == numbers[i - 1][j].value) {
							numbers[i][j].value *= 2;
							numbers[i][j].clr++;
							numbers[i - 1][j].value = 0;
							numbers[i - 1][j].clr = 0;
						}
					}
					k = nrow;
					for (int i = nrow - 1; i >= 0; i--) {
						if (numbers[i][j].value != 0) {
							std::swap(numbers[i][j], numbers[--k][j]);
						}
					}
				}

				////////
				for (int i = 0; i < nrow; i++) {
					if (CheckRow(i)) {
						spawnOnRow(i);
						test = true;
						break;
					}
				}
		}
		else if (kbd.KeyIsPressed(VK_LEFT)) {
				cooldown = true;
				////
				for (int i = 0; i < nrow; i++) {
					int k = -1;
					for (int j = 0; j < ncol; j++) {
						if (numbers[i][j].value != 0) {
							std::swap(numbers[i][j], numbers[i][++k]);
						}
					}

					for (int j = 0; j < ncol - 1; j++) {
						if (numbers[i][j + 1].value == numbers[i][j].value) {
							numbers[i][j].value *= 2;
							numbers[i][j].clr++;
							numbers[i][j + 1].value = 0;
							numbers[i][j + 1].clr = 0;
						}
					}

					k = -1;
					for (int j = 0; j < ncol; j++) {
						if (numbers[i][j].value != 0) {
							std::swap(numbers[i][j], numbers[i][++k]);
						}
					}
				}
				////
				for (int j = ncol - 1; j >= 0; j--) {
					if (CheckCol(j)) {
						spawnOnCol(j);
						test = true;
						break;
					}
				}
			
		}
		else if (kbd.KeyIsPressed(VK_RIGHT)) {
				cooldown = true;
				////
				for (int i = 0; i < nrow; i++) {
					int k = ncol;
					for (int j = ncol - 1; j >= 0; j--) {
						if (numbers[i][j].value != 0) {
							std::swap(numbers[i][j], numbers[i][--k]);
						}
					}

					for (int j = ncol - 1; j > 0; j--) {
						if (numbers[i][j - 1].value == numbers[i][j].value) {
							numbers[i][j].value *= 2;
							numbers[i][j].clr++;
							numbers[i][j - 1].value = 0;
							numbers[i][j - 1].clr = 0;
						}
					}

					k = ncol;
					for (int j = ncol - 1; j >= 0; j--) {
						if (numbers[i][j].value != 0) {
							std::swap(numbers[i][j], numbers[i][--k]);
						}
					}
				}
				////
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
	gfx.DrawCircle(xboard, yboard, thick, c);
	gfx.DrawCircle(xboard+ncol*cellWidth, yboard, thick, c);
	gfx.DrawCircle(xboard, yboard+nrow*cellHeight, thick, c);
	gfx.DrawCircle(xboard + ncol*cellWidth, yboard + nrow*cellHeight, thick, c);
}

void Board::DrawNR(Text & txt, Color c)
{
	
	for (int i = 0; i < nrow; i++) {
		int ypoz = i*textratio + textratio / 2 - 3;  //-3 cuz its 4x7
		for (int j = 0; j < ncol; j++) {
			if (numbers[i][j].value != 0) {
				DrawCell(j, i, Color(colors[numbers[i][j].clr][0], colors[numbers[i][j].clr][1], colors[numbers[i][j].clr][2]));
				int digits = txt.nrcifre(numbers[i][j].value);
				int xpoz = j*textratio + textratio / 2 - digits * 5 / 2 + 1; //same 
				txt.drawint(numbers[i][j].value, xpoz, ypoz, c);
			}
			else {
				DrawCell(j, i, Color(colors[0][0], colors[0][1], colors[0][2]));
			}
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
			numbers[i][nr].clr = 1;
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
			numbers[nr][j].clr = 1;
			spawned = true;
		}
	}
}


