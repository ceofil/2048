#include "Board.h"

Board::Board(Graphics & gfx, int xboard_in, int yboard_in, int cellWidth_in, int cellHeight_in, int row_nrcells, int col_nrcells)
	:
	gfx(gfx),
	xboard(xboard_in),
	yboard(yboard_in),
	cellWidth(cellWidth_in),
	cellHeight(cellHeight_in),
	nrow(row_nrcells),
	ncol(col_nrcells)
{
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
