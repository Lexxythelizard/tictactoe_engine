// --- include ---
#include <stdlib.h>
#include "../incls/tttio.h"
#include "../incls/tttutils.h"

// --- prototype ---
int	get_is_willing_to_continue(void);
int	get_user_option(char *menu, char **options);
// import

// --- DOC ---
/*
*/

/*
TTTUTILS_H

int     get_row_by_num(int num, t_finfo *finfo);
int     get_col_by_num(int num, t_finfo *finfo);
int     get_cell_by_row_col(int row, int col, t_finfo *finfo);
int     get_str_len(char *str);
int     get_nbr_from_base(char *inp, char *base);
char    *convert_nbr_to_base(int nbr, char *base);

TTTCORE_H
// read field
int             is_every_cell_written(t_finfo *finfo, char (*field)[finfo->columns]);
int             is_cell_written(t_finfo *finfo, int cell, char (*field)[finfo->columns]);
// win logic
int             is_won(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int             is_won_in_diagonal(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int             is_won_cols_rows(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int             is_won_in_row(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int             is_won_in_column(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
// field manipulation 2D
void    write_cell(t_finfo *finfo, char sign, int cell, char (*field)[finfo->columns]);
void    delete_cell(t_finfo *finfo, int cell, char (*field)[finfo->columns]);
void    delete_all_cells(t_finfo *finfo, char (*field)[finfo->columns]);
void    init_field(t_finfo *finfo, char (**field)[finfo->columns]);
void    free_field(t_finfo *finfo, char (**field)[finfo->columns]);
// validation
int             is_field_valid(t_finfo *finfo);
int             is_range_valid(t_finfo *finfo);
int             is_cell_input_valid(char *inp, t_finfo *finfo);
int             is_cell_in_field(int cell, t_finfo *finfo);
// setup values
void    set_base(t_finfo *finfo, int base);
void    set_field(t_finfo *finfo, int rows, int cols, int win_len);
void    set_player(t_player *player, char *name, char mark);

TTTIO_H
// string manipulation
char    *integrate_in_str(char *str, char **strs);
// get user input
char    *get_user_input(char *str);
char    *read_stdin(void);
// Convert_str_int
int     get_nbr_from_base(char *inp, char *base);
char    *convert_nbr_to_base(int nbr, char *base);
// terminal output
void    put_integrate_str_in_str(char *str, char **strs);
void    put_nbr_base(int nbr, char *base);
void    put_chr(char c);
void    put_str(char *str);

TTTUTILS_H
int             get_row_by_num(int num, t_finfo *finfo);
int             get_col_by_num(int num, t_finfo *finfo);
int             get_cell_by_row_col(int row, int col, t_finfo *finfo);
int             is_numeric(char *str);
int             is_element_in_arr(char c, char *str);
int             get_str_len(char *str);
char    *lxy_strcpy(char *src, char *dest)
*/

int	get_is_willing_to_continue(void)
{
	char	*temp_0;
	int		out;

	out = (-1);
	while (1)
	{
		temp_0 = get_user_input("new match? y/n: ");
		if (*temp_0 == 'y')
			out = 1;
		else if (*temp_0 == 'n')
			out = 0;
		free(temp_0);
		if (out >= 0)
			break ;
	}
	return (out);
}

int	get_user_option(char *menu, char **options)
{
	char	temp_0;
	int	out;
	int	i;

	out = (-1);
	while (out < 0)
	{
		i = 0;
		put_str(menu);
		temp_0 = get_user_input(menu);
		while (option[i] != NULL)
		{
			if (!(lxy_strcmp(temp_0, option[1])))
			{
				out = i;
				break ;
			}
			i++;
		}
		free(temp_0);
	}
	return (out);
}

