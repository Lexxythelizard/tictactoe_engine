// --- include ---
#include <unistd.h>
#include <stdio.h>
#include "../incls/meta.h"

// --- prototype ---
void	print_memory_arr(t_finfo *finfo, char (*field)[finfo->columns]);
void	print_field_arr(t_finfo *finfo, char (*field)[finfo->columns]);

//import
int	get_row_by_num(int num, t_finfo *finfo);
int	get_col_by_num(int num, t_finfo *finfo);

// --- DOC ---
// comment

// --- run ---


// --- define ---
void	print_memory_arr(t_finfo *finfo, char (*field)[finfo->columns])
{
	int	cell;
	int	cells;
	int	row;
	int	col;

	cell = FIRST_CELL;
	cells = ((*finfo).rows * (*finfo).columns);
	printf("---print memory addresses of %d - %d cells ---\n", cell, cells);
	while (cell <= cells)
	{
		row = get_row_by_num(cell, finfo);
		col = get_col_by_num(cell, finfo);
		printf("cell: %d row: %d, col: %d \t--> %p\n", \
				cell, row, col, &(field[row][col]));
		cell++;
	}
}

void	print_field_arr(t_finfo *finfo, char (*field)[finfo->columns])
{
	int	cell;
	int	cells;
	int	row;
	int	col;

	cell = FIRST_CELL;
	cells = ((*finfo).rows * (*finfo).columns);
	printf("---print values of %d - %d cells ---\n", cell, cells);
	while (cell <= cells)
	{
		row = get_row_by_num(cell, finfo);
		col = get_col_by_num(cell, finfo);
		printf("cell: %d row: %d, col: %d \t--> %c\n", \
				cell, row, col, field[row][col]);
		cell++;
	}
}
