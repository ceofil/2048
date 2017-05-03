#include "Board.h"

Board::Board(Graphics & gfx, Text& txt, int xboard_in, int yboard_in, int cellWidth_in, int cellHeight_in)
	:
	gfx(gfx),
	txt(txt),
	xboard(xboard_in),
	yboard(yboard_in),
	cellWidth(cellWidth_in),
	cellHeight(cellHeight_in)
{
	for (int i = 0; i < ncol; i++) {
		for (int j = 0; j < nrow; j++) {
			numbers[i][j].value = i*10+j;
		}
	}
	numbers[3][1].value = 0;
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


