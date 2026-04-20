// --- include ---
#include "../../incls/tttcore.h"
#include "../../incls/tttio.h"
#include "../../incls/terminal_menu.h"

// --- prototype ---
void	run_main_menu(t_finfo *finfo, t_player *pl);
// import
void	run_predefined_tables_menu(t_finfo *finfo, t_player *pl);
void	run_table_settings_menu(t_finfo *finfo, t_player *pl);
void	run_show_settings_menu(t_finfo *finfo, t_player *pl);
void	run_play_menu(t_finfo *finfo, t_player *pl);
void	run_show_info_menu(void);
int		get_user_option(char *menu, char **options);

// --- DOC ---
/*

*/

// --- define ---

// --- layer level NULL ---

/*
run main menu
	[X] exit
	[1] play predefined table
	[2] table settings
	[3] show settings
	[4] start
	[5] info
*/

void	run_main_menu(t_finfo *finfo, t_player *pl)
{
	int	main_opt;

	main_opt = (-1);
	while(main_opt)
	{
		put_str(SECTION_SEP);
		put_str(PATH_MAIN);
		put_str(HEAD_MAIN);
		main_opt = get_user_option(MENU_MAIN, OPT_MAIN);
		if (main_opt == 1)
			run_predefined_tables_menu(finfo, pl);
		else if (main_opt == 2)
			run_table_settings_menu(finfo, pl);
		else if (main_opt == 3)
			run_show_settings_menu(finfo, pl);
		else if (main_opt == 4)
			run_play_menu(finfo, pl);
		else if (main_opt == 5)
			run_show_info_menu();
		if (!(main_opt))
			put_str("Thanks for playing :)\n\n\tBye!\n\n");
	}
}
