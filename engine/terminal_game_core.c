// --- include ---
#include <stdlib.h>
#include "../incls/tttcore.h"
#include "../incls/tttio.h"
#include "../incls/tttutils.h"

// --- prototype ---
void	run_game(t_finfo *finfo, t_player pl[2]);
void	single_round(t_finfo *finfo, t_player pl[2], char (*field)[finfo->columns]);
void	single_turn(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
// import
// ../ui/cli/get_options.c
int	get_is_willing_to_continue(void);
int	get_user_option(char *menu, char **options);
// ../ui/cli/print_field.c
void	print_field(t_finfo *finfo, char (*field)[finfo->columns]);
void	put_sep_line_hor(t_finfo *finfo);
void	print_head(t_finfo *finfo);
// ../ui/cli/print_error_messages.c
void	print_to_few_arguments(int argc, int needed);
void	print_unvalid_field(void);
void	print_unvalid_win_len(void);
void	print_unvalid_mark(void);
void	print_cell_not_in_field(t_finfo *finfo, int cell);
void	print_unvalid_input(t_finfo *finfo, char *input);
void	print_cell_already_written(t_finfo *finfo, int cell);
// ../ui/cli/print_game_messages.c
void	print_whos_turn(t_player *pl);
void	print_won_message(t_player *pl);
void	print_draw_message(void);
void	print_new_round(t_player *pl1, t_player *pl2);
void	print_round_ends(void);

// --- DOC ---
/*
cc -Wall -Wextra -Werror ./playable_prototype/first_prototype.c ./ui/cli/print_field.c \
./ui/cli/print_error_messages.c ./ui/cli/print_game_messages.c \
-L ./ttt_lib/ -l tttcore -l tttio -l tttutils -o ./play/prototype
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

// --- define ---

void	run_game(t_finfo *finfo, t_player pl[2])
{
	char	(*field)[MIN_WIDTH];

	init_field(finfo, &field);
	while (1)
	{
		single_round(finfo, pl, field);
		print_round_ends();
		if (!(get_is_willing_to_continue()))
			break ;
		delete_all_cells(finfo, field);
	}
	free_field(finfo, &field);
	return (0);
}

/*
later *pl and last element NULL
*/
void	single_round(t_finfo *finfo, t_player pl[2], char (*field)[finfo->columns])
{
	int	turn;
	int	draw;

	turn = 0;
	draw = 1;
	print_new_round(&pl[0], &pl[1]);
	while (!(is_every_cell_written(finfo, field)))
	{
		print_head(finfo);
		print_field(finfo, field);
		print_whos_turn(&pl[(turn % 2)]);
		single_turn(finfo, pl[(turn % 2)].mark, field);
		if (is_won(finfo, pl[(turn % 2)].mark, field))
		{
			draw = 0;
			break ;
		}
		turn += 1 - (2 * (turn % 2));
	}
	print_field(finfo, field);
	if (draw)
		print_draw_message();
	else
		print_won_message(&pl[(turn % 2)]);
}

void	single_turn(t_finfo *finfo, char mark, char (*field)[finfo->columns])
{
	char	*temp;
	int		cell;

	while (!(is_every_cell_written(finfo, field)))
	{
		temp = get_user_input("write cell: ");
		cell = get_nbr_from_base(temp, (*finfo).base_str);
		if (!(is_cell_input_valid(temp, finfo)))
		{
			print_unvalid_input(finfo, temp);
			free(temp);
			continue ;
		}
		free(temp);
		if (!(is_cell_in_field(cell, finfo)))
			print_cell_not_in_field(finfo, cell);
		else if (is_cell_written(finfo, cell, field))
			print_cell_already_written(finfo, cell);
		else
		{
			write_cell(finfo, mark, cell, field);
			break ;
		}
	}
}
