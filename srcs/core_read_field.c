// +++++++++++ CORE read_field +++++++++++++++

// --- include ---
#include <unistd.h>
#include "../incls/meta.h"

// --- prototype ---
int	is_every_cell_written(t_finfo *finfo, char (*field)[finfo->columns]);
int	is_cell_written(t_finfo *finfo, int cell, char (*field)[finfo->columns]);

//import
int	get_row_by_num(int num, t_finfo *finfo);
int	get_col_by_num(int num, t_finfo *finfo);

// --- DOC ---
/*
TODO:
	- test		is_every_cell_written()			: DONE
	- test		is_cell_written()			: DONE
*/
// --- run ---


// --- define ---
int	is_every_cell_written(t_finfo *finfo, char (*field)[finfo->columns])
{
	int	row;
	int	col;

	col = 0;
	while (col < (*finfo).columns)
	{
		row = 0;
		while (row < (*finfo).rows)
		{
			if (field[row][col] == EMPTY)
				return (0);
			row++;
		}
		col++;
	}
	return (1);
}

int	is_cell_written(t_finfo *finfo, int cell, char (*field)[finfo->columns])
{
	if (field[get_row_by_num(cell, finfo)][get_col_by_num(cell, finfo)] == EMPTY)
		return (0);
	return (1);
}
