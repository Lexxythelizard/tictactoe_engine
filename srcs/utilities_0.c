// --- include ---
#include <unistd.h>
#include "../incls/meta.h"

// --- include ---
int	get_row_by_num(int num, t_finfo *finfo);
int	get_col_by_num(int num, t_finfo *finfo);
int	get_cell_by_row_col(int row, int col, t_finfo *finfo);

// --- DOC ---
/*
TODO:
	- test		get_row_by_num		: DONE
	- test		get_col_by_num		: DONE
	- test		get_cell_by_row_col	: 
*/

// --- run ---


// --- define ---

int	get_row_by_num(int num, t_finfo *finfo)
{
	return ((int)((num - 1) / (*finfo).columns));
}

/*
	return: (num - COLUMNS * row - 1)
*/

int	get_col_by_num(int num, t_finfo *finfo)
{
	return (num - (*finfo).columns * ((int)((num - 1) / (*finfo).columns)) - 1);
}

int	get_cell_by_row_col(int row, int col, t_finfo *finfo)
{
	return (row * (*finfo).columns + col + 1);
}
