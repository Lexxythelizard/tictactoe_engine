// --- include ---
#include "../../incls/tttcore.h"
#include "../../incls/tttio.h"
#include "../../incls/terminal_menu.h"

// --- prototype ---
void	run_custom_field_menu(t_finfo *finfo);
void	run_number_of_player_menu(t_player *pl);
void	run_edit_player_menu(t_player *pl);
// import
int	get_user_option(char *menu, char **options);

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
	int	rows;
	int	cols;
	int	win_len;

	while (1)
	{
		rows = 0;
		cols = 0;
		win_len = 0;
		while (!(rows && cols && win_len))
		{
			// rows = get_user_input_int();
			// cols = get_user_input_int();
			// win_len = get_user_input_int();
		}
		set_field(finfo, rows, cols, win_len);
		// if field valid
			// break ;
		// not get option retry:
			// break ; 
	}
}

void	run_number_of_player_menu(t_player *pl)
{
	int	player_opt;

	player_opt = (-1);
	while (player_opt)
	{
		put_str("...under construction...\n");
		break ;
	}
}

void	run_edit_player_menu(t_player *pl)
{
	int	player_opt;

	player_opt = (-1);
	while (player_opt)
	{
		put_str("...under construction...\n");
		break ;
	}
}
