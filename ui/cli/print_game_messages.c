// --- include ---
#include <unistd.h>
#include "../../incls/tttio.h"
#include "../../incls/tttcore.h"
#include "../../incls/player.h"

// --- proto ---
void	print_whos_turn(t_player *pl);
void	print_won_message(t_player *pl);
void	print_draw_message(void);
void	print_new_round(t_player *pl1, t_player *pl2);
void	print_round_ends(void);

// import
void	print_str_with_vals(char *str, int **vals);
void	put_chr(char c);
void	put_str(char *str);
int	get_str_len(char *str);
char	*convert_nbr_to_base(int nbr, char *base);

void	print_whos_turn(t_player *pl)
{
	put_str((*pl).name);
	put_str("'s turn. \n");
}

void	print_won_message(t_player *pl)
{
	put_str((*pl).name);
	put_str(" has won!\n");
}

void	print_draw_message(void)
{
	put_str("It's a draw!\n");
}


void	print_new_round(t_player *pl1, t_player *pl2)
{
	put_str("New round:\n");
	put_str((*pl1).name);
	put_str(" got: ");
	put_chr((*pl1).mark);
	put_chr('\n');
	put_str((*pl2).name);
	put_str(" got: ");
	put_chr((*pl2).mark);
	put_str("\n\n");
}

void	print_round_ends(void)
{
	put_str("Round finished!\n\n");
}
