// --- include ---
#include <unistd.h>
#include "../incls/meta.h"

// --- include ---
int	get_row_by_num(int num, t_finfo *finfo);
int	get_col_by_num(int num, t_finfo *finfo);
int	get_cell_by_row_col(int row, int col, t_finfo *finfo);
int	get_str_len(char *str);
int	get_len_of_number(int nbr, int base);

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

int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	get_len_of_number(int nbr, int base)
{
	int len;
	int divisor;

	len = 1;
	divisor = 1;
	if (nbr < 0)
		len++;
	else
		nbr *= (-1);
	while ((int)(nbr / divisor) <= -base)
	{
		divisor *= base;
		len++;
	}
	return (len);
}
