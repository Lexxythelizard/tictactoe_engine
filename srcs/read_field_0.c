// --- include ---
#include <unistd.h>
#include "meta.h"

// --- prototype ---
int	is_every_cell_written(t_finfo *finfo, char (*field)[finfo->columns]);
int	is_cell_written(t_finfo *finfo, int cell, char (*field)[finfo->columns]);
int	is_won_in_row(t_finfo *finfo, char mark, int row, char (*field)[finfo->columns]);
int	is_won_in_column(t_finfo *finfo, char mark, int col, char (*field)[finfo->columns]);

//import
int	get_row_by_num(int num, t_finfo *finfo);
int	get_col_by_num(int num, t_finfo *finfo);

// --- DOC ---
// comment

// --- run ---


// --- define ---
int	is_every_cell_written(t_finfo *finfo, char (*field)[finfo->columns])
{
	int	cell;
	int	cells;

	cell = FIRST_CELL;
	cells = ((*finfo).rows * (*finfo).columns);
	while (cell <= cells)
	{
		if (cell == EMPTY)
			return (0);
		cell++;
	}
	return (1);
}

int	is_cell_written(t_finfo *finfo, int cell, char (*field)[finfo->columns])
{
	if (field[get_row_by_num(cell, finfo)][get_column_by_num(cell, finfo)] == EMPTY)
		return (0);
	return (1);
}

int	is_won_in_row(t_finfo *finfo, char mark, int row, char (*field)[finfo->columns])
{
	int	count;
	int	col;

	count = 0;
	col = 0;
	while (col <= (*finfo).columns)
	{
		if (field[row][col] == mark)
			count++;
		else
			count = 0;
		if (count >= (*finfo).win_len)
			return (1);
		col++;
	}
	return (0);
}

int	is_won_in_column(t_finfo *finfo, char mark, int col, char (*field)[finfo->columns])
{
	int	count;
	int	row;

	count = 0;
	row = 0;
	while (row <= (*finfo).rows)
	{
		if (field[row][col] == mark)
			count++;
		else
			count = 0;
		if (count >= (*finfo).win_len)
			return (1);
		row++;
	}
	return (0);
