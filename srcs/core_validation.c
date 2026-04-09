// --- include ---
#include "../incls/field.h"

// --- prototype ---
int	is_field_valid(t_finfo *finfo);
int	is_range_valid(t_finfo *finfo);
int	is_cell_input_valid(char *inp, t_finfo *finfo);
int	is_cell_in_field(int cell, t_finfo *finfo);

// imports
int     is_element_in_arr(char c, char *str);

// --- doc ---
/*
TODO:
	- test	is_field_valid			: DONE
	- test	is_range_valid			: DONE
	- test	is_cel_input_valid		: DONE 
	- test	is_cell_in_field		: DONE
*/

// --- run ---


// --- define ---
int	is_field_valid(t_finfo *finfo)
{
	if (((*finfo).rows < MIN_LEN) || ((*finfo).columns < MIN_WIDTH))
		return (0);
	return (1);
}

int	is_range_valid(t_finfo *finfo)
{
	if ((*finfo).win_len < MIN_RANGE)
		return (0);
	if (((*finfo).win_len > (*finfo).rows) || ((*finfo).win_len > (*finfo).columns))
		return (0);
	return (1);
}

int	is_cell_input_valid(char *inp, t_finfo *finfo)
{
	while (*inp)
	{
		if (!(is_element_in_arr(*inp, (*finfo).base_str)))
			return (0);
		inp++;
	}
	return (1);
}

int	is_cell_in_field(int cell, t_finfo *finfo)
{
	if ((cell < FIRST_CELL) || (cell > ((*finfo).rows * (*finfo).columns)))
		return (0);
	return (1);
}
