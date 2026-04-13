// --- include ---
#include "../../incls/tttcore.h"
#include "../../incls/tttio.h"
#include "../../incls/terminal_menu.h"

// --- prototype ---
void	run_predefined_tables_menu(t_finfo *finfo, t_player *pl);
void	run_table_settings_menu(t_finfo *finfo, t_player *pl);
void	run_show_settings_menu(t_finfo *finfo, t_player *pl);
void	run_play_menu(t_finfo *finfo, t_player *pl);
void	run_show_info_menu(void);
// import
// ./engine/terminal_game_core.c
void	run_game(t_finfo *finfo, t_player pl[2]);
// ./game/[sniggle].c
void	set_field_classic_tictactoe(t_finfo *finfo, t_player *pl);
void	set_field_four_in_a_row(t_finfo *finfo, t_player *pl);
void	set_field_four_in_a_row_wide(t_finfo *finfo, t_player *pl);
void	set_field_four_in_a_row_huge(t_finfo *finfo, t_player *pl);
void	set_field_four_in_a_row_wide_hex(t_finfo *finfo, t_player *pl);
// ./game/terminal_menu_layer_sec.c
void	run_field_menu(t_finfo *finfo);
void	run_player_menu(t_player *pl);
void	run_base_menu(t_finfo *finfo);
// ./ui/cli/print_stats.c
void	print_field_settings(t_finfo *finfo);
void	print_palyers(t_player *pl, int n);
void	print_player(t_player *pl);
void	print_base_settings(t_finfo *finfo);
// ./ui/cli/get_user_options.c
int		get_user_option(char *menu, char **options);
// --- DOC ---
/*

*/

// --- define ---

// --- layer level first ---

/*
run predefined table menu
	[X] back
	[1] classic tictactoe
	[2] four in a row
	[2] four in a row huge table
	[2] four in a row
*/

void	run_predefined_tables_menu(t_finfo *finfo, t_player *pl)
{
	int	predef_opt;

	predef_opt = (-1);
	while (predef_opt)
	{
		put_str(HEAD_PRED);
		put_str(PATH_PRED);
		predef_opt = get_user_option(MENU_PRED, OPT_PRED);
		if (predef_opt == 1)
			set_field_classic_tictactoe(finfo, pl);
		else if (predef_opt == 2)
			set_field_four_in_a_row(finfo, pl);
		else if (predef_opt == 3)
			set_field_four_in_a_row_wide(finfo, pl);
		else if (predef_opt == 4)
			set_field_four_in_a_row_huge(finfo, pl);
		else if (predef_opt == 5)
			set_field_four_in_a_row_wide_hex(finfo, pl);
		if (predef_opt)
			run_game(finfo, pl);
	}
}

/*
run table settings menu
	[X] back
	[1] set field
	[2] set player
	[2] set base
*/

void	run_table_settings_menu(t_finfo *finfo, t_player *pl)
{
	int	settings_opt;

	settings_opt = (-1);
	while (settings_opt)
	{
		put_str(HEAD_TSET);
		put_str(PATH_TSET);
		settings_opt = get_user_option(MENU_TSET, OPT_TSET);
		if (settings_opt == 1)
			run_field_menu(finfo);
		if (settings_opt == 2)
			run_player_menu(pl);
		if (settings_opt == 3)
			run_base_menu(finfo);
	}
}

/*
run show settings menu
	[X] back
*/

void	run_show_settings_menu(t_finfo *finfo, t_player *pl)
{
	int	show_opt;

	show_opt = (-1);
	while (show_opt)
	{
		put_str(HEAD_SHOW);
		put_str(PATH_SHOW);
		print_field_settings(finfo);
		print_palyers(pl, 2);
		print_base_settings(finfo);
		show_opt = get_user_option(MENU_SHOW, OPT_SHOW);
	}
}

/*
run play menu
	[X] back
	[1] playerer name	set
	[2] play
*/

void	run_play_menu(t_finfo *finfo, t_player *pl)
{
	int	play_opt;

	play_opt = (-1);
	while (play_opt)
	{
		put_str(HEAD_PLAY);
		put_str(PATH_PLAY);
		print_field_settings(finfo);
		print_palyers(pl, 2);
		print_base_settings(finfo);
		play_opt = get_user_option(MENU_PLAY, OPT_PLAY);
		if (play_opt == 1)
			put_str("menu layer thi: edit player:\n...under construction\n\n");
			//call set_player_name();
		if (play_opt == 2)
			run_game(finfo, pl);
	}
}

/*
run show info menu
	[X] back
*/

void	run_show_info_menu(void)
{
	int	show_opt;

	show_opt = (-1);
	put_str(HEAD_INFO);
	put_str(PATH_INFO);
	while (show_opt)
	{
		//display info
		put_str("...under construction...\n\n");
		show_opt = get_user_option(MENU_INFO, OPT_INFO);
	}
}
