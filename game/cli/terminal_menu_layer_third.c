// --- include ---
#include "../../incls/tttcore.h"
#include "../../incls/tttio.h"
#include "../../incls/terminal_menu.h"

// --- prototype ---
void	run_custom_field_menu(t_finfo *finfo);
void	run_number_of_player_menu(t_player *pl);
void	run_edit_player_menu(t_player *pl);
// import
int		get_user_option(char *menu, char **options);
int		get_integer_from_user_input(void);
// ./ui/cli/print_stats.c
void	print_field_settings(t_finfo *finfo);
// ./ui/cli/print_err_messages.c
void	print_unvalid_field(void);
void	print_unvalid_win_len(void);
// ./engine/... .c
void	correct_field(t_finfo *finfo);
// ./game/cli/print_stats.c
// --- DOC ---
/*

*/

// --- define ---

// --- layer level third ---

/*
run field menu
	[X] back
	[1] 3 x 3 field		3 to win
	[2] 4 x 5 field		4 to win
	[3] 7 x 7 field		4 to win
	[4] custom field	...
*/

void	run_custom_field_menu(t_finfo *finfo)
{
	int	custom_opt;

	custom_opt = (-1);
	put_str(SECTION_SEP);
	put_str(PATH_CUSFIELD);
	put_str(HEAD_CUSFIELD);
	while (custom_opt)
	{
		custom_opt = get_user_option(MENU_CUSFIELD, OPT_CUSFIELD);
		if (custom_opt == 1)
			set_field_rows(finfo, get_integer_from_user_input());
		else if (custom_opt == 2)
			set_field_cols(finfo, get_integer_from_user_input());
		else if (custom_opt == 3)
			set_field_range(finfo, get_integer_from_user_input());
		else if (custom_opt == 4)
			print_field_settings(finfo);
		if (!(is_field_valid(finfo)))
			print_unvalid_field();
		if (!(is_range_valid(finfo)))
			print_unvalid_win_len();
		if (!(custom_opt))
			correct_field(finfo);
	}
	print_field_settings(finfo);
}

void	run_number_of_player_menu(t_player *pl)
{
	int	player_opt;

	(void)(pl);
	player_opt = (-1);
	while (player_opt)
	{
		put_str(SECTION_SEP);
		put_str(PATH_PLAYER_N);
                put_str(HEAD_PLAYER_N);
                player_opt = get_user_option(MENU_PLAYER_N, OPT_PLAYER_N);
		break ;
	}
}

void	run_edit_player_menu(t_player *pl)
{
	int	player_opt;

	(void)(pl);
	player_opt = (-1);
	while (player_opt)
	{
		put_str(SECTION_SEP);
		put_str(PATH_PLAYER_M);
                put_str(HEAD_PLAYER_M);
                player_opt = get_user_option(MENU_PLAYER_M, OPT_PLAYER_M);
		break ;
	}
}
