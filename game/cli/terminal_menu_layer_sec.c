// --- include ---
#include "../../incls/tttcore.h"
#include "../../incls/tttio.h"
#include "../../incls/terminal_menu.h"

// --- prototype ---
void	run_field_menu(t_finfo *finfo);
void	run_player_menu(t_player *pl);
void	run_base_menu(t_finfo *finfo);
// import
// path
void	run_custom_field_menu(t_finfo *finfo);
void	run_number_of_player_menu(t_player *pl);
void	run_edit_player_menu(t_player *pl);
// path
int	get_user_option(char *menu, char **options);

// --- DOC ---
/*

*/

// --- define ---

// --- layer level sec ---

/*
run field menu
	[X] back
	[1] 3 x 3 field		3 to win
	[2] 4 x 5 field		4 to win
	[3] 7 x 7 field		4 to win
	[4] custom field	...
*/

void	run_field_menu(t_finfo *finfo)
{
	int	field_opt;

	field_opt = (-1);
	while (field_opt)
	{
		put_str(HEAD_FIELD);
		put_str(PATH_FIELD);
		field_opt = get_user_option(MENU_FIELD, OPT_FIELD);
		if (field_opt == 1)
			set_field(finfo, 3, 3, 3);
		if (field_opt == 2)
			set_field(finfo, 4, 5, 4);
		if (field_opt == 3)
			set_field(finfo, 7, 7, 4);
		if (field_opt == 4)
			run_custom_field_menu(finfo);
	}
}

/*
run player menu
	[X] back
	[1] number of player
	[2] set player name
*/

void	run_player_menu(t_player *pl)
{
	int	player_opt;

	player_opt = (-1);
	while (player_opt)
	{
		put_str(HEAD_PLAYER);
		put_str(PATH_PLAYER);
		player_opt = get_user_option(MENU_PLAYER, OPT_PLAYER);
		if (player_opt == 1)
			run_number_of_player_menu();
		if (player_opt == 2)
			run_edit_player_menu();
	}
}

/*
run base menu
	[X] back
	[2] set player name
	[8] set player name
	[10] set player name
	[12] set player name
	[16] set player name
*/

void	run_base_menu(t_finfo *finfo)
{
	int	base_opt;

	base_opt = (-1);
	while (base_opt)
	{
		put_str();
		put_str();
		base_opt = get_user_option(sniggle, sniggle2);
		if (base_opt == 2)
			//set base
		if (base_opt == 8)
			//set base
		if (base_opt == 10)
			//set base
		if (base_opt == 12)
			//set base
		if (base_opt == 16)
			//set base
		if (base_opt == 1)
			//set base
	}
}
