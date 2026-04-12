// --- include ---
#include <stdlib.h>
#include "../../incls/tttcore.h"
#include "../../incls/tttio.h"
#include "../../incls/tttutils.h"

// --- prototype ---
void	set_field_classic_tictactoe(t_finfo *finfo, t_player *pl);
void	set_field_four_in_a_row(t_finfo *finfo, t_player *pl);
void	set_field_four_in_a_row_wide(t_finfo *finfo, t_player *pl);
void	set_field_four_in_a_row_huge(t_finfo *finfo, t_player *pl);
void	set_field_four_in_a_row_wide_hex(t_finfo *finfo, t_player *pl);

// --- DOC ---

/*
	if (!(is_field_valid(&finfo)))
		print_unvalid_field();
	if (!(is_range_valid(&finfo)))
		print_unvalid_win_len();
	if ((!(is_field_valid(&finfo))) || (!(is_range_valid(&finfo))))
		return (0);
*/

// --- define ---

/*
	set classic tictactoe
	cells	3 x 3	
	win len	3

	Player 1:	X
	Player 2:	O

	Base:	10
*/

void	set_field_classic_tictactoe(t_finfo *finfo, t_player *pl)
{
	set_field(finfo, 3, 3, 3);
	set_base(finfo, 10);
	set_player(&pl[0], P1, X);
	set_player(&pl[1], P2, O);
}

/*
	set field_four_in_a_row
	cells	4 x 5	
	win len	4

	Player 1:	X
	Player 2:	O

	Base:	10
*/

void	set_field_four_in_a_row(t_finfo *finfo, t_player *pl)
{
	set_field(finfo, 4, 5, 4);
	set_base(finfo, 10);
	set_player(&pl[0], P1, X);
	set_player(&pl[1], P2, O);
}

/*
	set field_four_in_a_row_wide
	cells	5 x 7	
	win len	4

	Player 1:	X
	Player 2:	O

	Base:	10
*/

void	set_field_four_in_a_row_wide(t_finfo *finfo, t_player *pl)
{
	set_field(finfo, 5, 7, 4);
	set_base(finfo, 10);
	set_player(&pl[0], P1, X);
	set_player(&pl[1], P2, O);
}

/*
	set four in a row huge
	cells	7 x 7
	win len	4

	Player 1:	X
	Player 2:	O

	Base:	10
*/

void	set_field_four_in_a_row_huge(t_finfo *finfo, t_player *pl)
{
	set_field(finfo, 7, 7, 4);
	set_base(finfo, 10);
	set_player(&pl[0], P1, X);
	set_player(&pl[1], P2, O);
}

/*
	set four in a row wide hex
	cells	7 x 7
	win len	4

	Player 1:	X
	Player 2:	O

	Base:	16
*/

void	set_field_four_in_a_row_wide_hex(t_finfo *finfo, t_player *pl)
{
	set_field(finfo, 5, 7, 4);
	set_base(finfo, 16);
	set_player(&pl[0], P1, X);
	set_player(&pl[1], P2, O);
}
