// --- include ---
#include <stdlib.h>
#include "../incls/field.h"

// --- prototype ---
void	write_cell(t_finfo *finfo, char sign, int cell, char (*field)[finfo->columns]);
void	delete_cell(t_finfo *finfo, int cell, char (*field)[finfo->columns]);
void	delete_all_cells(t_finfo *finfo, char (*field)[finfo->columns]);
void	init_field(t_finfo *finfo, char (**field)[finfo->columns]);
void	free_field(t_finfo *finfo, char (**field)[finfo->columns]);

// import
int	get_row_by_num(int num, t_finfo *finfo);
int	get_col_by_num(int num, t_finfo *finfo);

// --- DOC ---
/*
TODO:
	- implement	write_cell()		: DONE
	- implement	delete_cell()		: DONE
	- implement	delete_all_cells()	: DONE
	- test		write_cell()		: DONE
	- test		delete_cell()		: DONE
	- test		delete_all_cells()	: DONE
	- implement	init_field()		: DONE
	- test		init_field()		: DONE
	- implement	free_field()		: DONE
	- test		free_field()		: DONE
	- check		memory of field arr	: DONE
	- -  write 	print_memory()		: DONE
*/

// --- run ---


// --- define ---

void	write_cell(t_finfo *finfo, char sign, int cell, char (*field)[finfo->columns])
{
	field[get_row_by_num(cell, finfo)][get_col_by_num(cell, finfo)] = sign;
}

void	delete_cell(t_finfo *finfo, int cell, char (*field)[finfo->columns])
{
	field[get_row_by_num(cell, finfo)][get_col_by_num(cell, finfo)] = EMPTY;
}

void	delete_all_cells(t_finfo *finfo, char (*field)[finfo->columns])
{
	int	cell;
	int	cells;

	cell = FIRST_CELL;
	cells = ((*finfo).rows * (*finfo).columns);
	while (cell <= cells)
	{
		delete_cell(finfo, cell, field);
		cell++;
	}
}

void	init_field(t_finfo *finfo, char (**field)[finfo->columns])
{
	*field = malloc((*finfo).rows * sizeof(**field));
	if (!(*field))
		return ;
	delete_all_cells(finfo, *field);
}

void	free_field(t_finfo *finfo, char (**field)[finfo->columns])
{
	(void)finfo;
	free(*field);
	*field = NULL;
}
