// --- include ---
#include "../incls/field.h"
#include "../incls/player.h"

// --- prototype ---
void	set_player(t_player *player, char *name, char mark);
void	set_player_name(t_player *player, char *name);
void	set_player_mark(t_player *player, char mark);

// --- DOC ---
/*
TODO:
	- implement	set_base()		: DONE
	- test		set_base()		: DONE
	- implement	set_player()		: DONE
	- implement	set_field()		: DONE
	- implement	...			: 
	- test		set_player()		: DONE 
*/

// --- run ---


// --- define ---

void	set_player(t_player *player, char *name, char mark)
{
	(*player).name = name;
	(*player).mark = mark;
}

void	set_player_name(t_player *player, char *name)
{
	(*player).name = name;
}

void	set_player_mark(t_player *player, char mark)
{
	(*player).mark = mark;
}

