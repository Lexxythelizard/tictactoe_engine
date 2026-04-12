// --- include ---
#include <stdlib.h>
#include "../../incls/tttio.h"
#include "../../incls/field.h"
#include "../../incls/player.h"

// --- proto ---
void	print_field_settings(t_finfo *finfo);
void	print_palyers(t_player *pl, int n);
void	print_player(t_player *pl);
void	print_base_settings(t_finfo *finfo);
// import

// --- DOC ---
// comment

// --- define ---

void	print_field_settings(t_finfo *finfo)
{
	put_str("field replace\n");		// replace
	put_str(FINFO_ROWS);
	put_nbr_base((*finfo).rows, DEC_BASE);
	put_newline();
	put_str(FINFO_COLS);
	put_nbr_base((*finfo).columns, DEC_BASE);
	put_newline();
	put_str(FINFO_WLEN);
	put_nbr_base((*finfo).win_len, DEC_BASE);
	put_newlines(2);
}

void	print_palyers(t_player *pl, int n)
{
	int	i;

	i = 0;
	while ((pl[i] != NULL) && (i < n))
	{
		put_str(PLAYER_NULL);
		put_nbr_base((i + 1), DEC_BASE);
		put_newline();
		print_player(&(pl[i]));
		i++;
	}
}

void	print_player(t_player *pl)
{
	put_str(PLAYER_NAME);
	put_str((*pl).name);
	put_newline();
	put_str(PLAYER_MARK);
	put_chr((*pl).mark);
	put_newlines(2);
}

void	print_base_settings(t_finfo *finfo)
{
	put_str("base replace \n");		//replace
	put_newline();
	put_str(FINFO_BASE_I);
	put_nbr_base((*finfo).base, DEC_BASE);
	put_newline();
	put_str(FINFO_BASE_S);
	put_str((*finfo).base_str);
	put_newlines(2);
}

