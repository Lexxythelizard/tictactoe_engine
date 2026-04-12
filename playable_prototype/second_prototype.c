// --- include ---
#include <stdlib.h>
#include "../incls/tttcore.h"
#include "../incls/tttio.h"
#include "../incls/tttutils.h"

// --- prototype ---
// import
void	run_main_menu(t_finfo *finfo, t_player *pl);

// --- run ---

/*
cc -Wall -Wextra -Werror ./playable_prototype/second_prototype \
./engine/terminal_game_core.c \
./game/cli/terminal_menu_layer_zero.c \
./game/cli/terminal_menu_layer_first.c ./game/cli/terminal_menu_layer_sec.c \
./game/cli/terminal_menu_layer_third.c ./game/cli/terminal_set_predefined_field.c \
./ui/cli/print_field.c ./ui/cli/print_error_messages.c ./ui/cli/print_game_messages.c \
./ui/cli/print_stats.c ./ui/cli/get_options.c \
./incls/terminal_menu.h \
-L ./ttt_lib/ -l tttcore -l tttio -l tttutils -o ./play/prototype_two 
*/

// --- run ---
int	main(void)
{
	t_finfo		finfo;
	t_player	pl[2];

	set_field(&finfo, 3, 3, 3);
	set_base(&finfo, 10);
	set_player(&pl[0], P1, X);
	set_player(&pl[1], P2, O);
	
	run_main_menu(&finfo, pl);
	return (0);
}

/*
	if (!(is_field_valid(&finfo)))
		print_unvalid_field();
	if (!(is_range_valid(&finfo)))
		print_unvalid_win_len();
	if ((!(is_field_valid(&finfo))) || (!(is_range_valid(&finfo))))
		return (0);
*/
