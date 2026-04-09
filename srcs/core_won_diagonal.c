// --- include ---
#include "../incls/field.h"

// --- prototype ---
int	is_won_in_diagonal(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int	is_won_in_backslash_row(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int	is_won_in_backslash_col(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int	is_won_in_slash_row(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int	is_won_in_slash_col(t_finfo *finfo, char mark, char (*field)[finfo->columns]);

// --- DOC ---
/*
TODO:
	- implement	is_won_in_diagonal()				: DONE
	- implement	is_won_in_backslash_row()			: DONE
	- implement	is_won_in_backslash_col()			: DONE
	- implement	is_won_in_slash_row()				: DONE
	- implement	is_won_in_slash_col()				: DONE
	- test		is_won_in_diagonal()				: DONE
	- test		is_won_in_backslash_row()			: DONE
	- test		is_won_in_backslash_col()			: DONE
	- test		is_won_in_slash_row()				: DONE
	- test		is_won_in_slash_col()				: DONE
*/

// --- run ---


// --- define ---
int	is_won_in_diagonal(t_finfo *finfo, char mark, char (*field)[finfo->columns])
{
	if (is_won_in_backslash_row(finfo, mark, field))
		return (1);
	if (is_won_in_backslash_col(finfo, mark, field))
		return (1);
	if (is_won_in_slash_row(finfo, mark, field))
		return (1);
	if (is_won_in_slash_col(finfo, mark, field))
		return (1);
	return (0);
}

int	is_won_in_backslash_row(t_finfo *finfo, char mark, char (*field)[finfo->columns])
{
	int	count;
	int	row;
	int	col;
	int	i;

	row = 0;
	col = 0;
	while (row <= ((*finfo).rows - (*finfo).win_len))
	{
		i = 0;
		count = 0;
		while (((col + i) < (*finfo).columns) && ((row + i) < (*finfo).rows))
		{
			if (field[row + i][col + i] == mark)
				count++;
			else
				count = 0;
			if (count >= (*finfo).win_len)
				return (1);
			i++;
		}
		row++;
	}
	return (0);
}

int	is_won_in_backslash_col(t_finfo *finfo, char mark, char (*field)[finfo->columns])
{
	int	count;
	int	row;
	int	col;
	int	i;

	row = 0;
	col = 0;
	while (col <= ((*finfo).columns - (*finfo).win_len))
	{
		i = 0;
		count = 0;
		while (((col + i) < (*finfo).columns) && ((row + i) < (*finfo).rows))
		{
			if (field[row + i][col + i] == mark)
				count++;
			else
				count = 0;
			if (count >= (*finfo).win_len)
				return (1);
			i++;
		}
		col++;
	}
	return (0);
}

int	is_won_in_slash_row(t_finfo *finfo, char mark, char (*field)[finfo->columns])
{
	int	count;
	int	row;
	int	col;
	int	i;

	row = 0;
	col = (*finfo).columns - 1;
	while (row <= ((*finfo).rows - (*finfo).win_len))
	{
		i = 0;
		count = 0;
		while (((col - i) >= 0) && ((row + i) < (*finfo).rows))
		{
			if (field[row + i][col - i] == mark)
				count++;
			else
				count = 0;
			if (count >= (*finfo).win_len)
				return (1);
			i++;
		}
		row++;
	}
	return (0);
}

int	is_won_in_slash_col(t_finfo *finfo, char mark, char (*field)[finfo->columns])
{
	int	count;
	int	row;
	int	col;
	int	i;

	row = 0;
	col = (*finfo).columns - 1;
	while ((col - (*finfo).win_len + 1) >= 0)
	{
		i = 0;
		count = 0;
		while (((col - i) >= 0) && ((row + i) < (*finfo).rows))
		{
			if (field[row + i][col - i] == mark)
				count++;
			else
				count = 0;
			if (count >= (*finfo).win_len)
				return (1);
			i++;
		}
		col--;
	}
	return (0);
}
