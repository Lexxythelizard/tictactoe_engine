// --- include ---
#include <stdlib.h>
#include "../incls/tttcore.h"
#include "../incls/tttio.h"
#include "../incls/tttutils.h"

// --- prototype ---
void	correct_field(t_finfo *finfo);
// import
// ../ui/cli/get_options.c
int	get_is_willing_to_continue(void);
int	get_user_option(char *menu, char **options);
// ../ui/cli/print_field.c
void	print_field(t_finfo *finfo, char (*field)[finfo->columns]);
void	put_sep_line_hor(t_finfo *finfo);
void	print_head(t_finfo *finfo);
void	print_round_seperator(void);
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

	// if field measures not valid
	//	finfo-> rows = max (rows, MIN_LEN)
	//	finfo-> cols = max (cols, MIN_WIDTH)
	// if range is not valid
	// 	finfo -> range = max( (rows,cols), MIN_RANGE)

void	correct_field(t_finfo *finfo)
{
	if (!(is_field_valid(finfo)))
	{
		(*finfo).rows = get_max((*finfo).rows, MIN_LEN);
		(*finfo).columns = get_max((*finfo).columns, MIN_WIDTH);
	}
	if (!(is_range_valid(finfo)))
	{
		(*finfo).win_len = get_max(
				get_min((*finfo).rows, (*finfo).columns), MIN_LEN);
	}
}
