// --- include ---
#include "../incls/field.h"
#include "../incls/player.h"

// --- prototype ---
void	set_field(t_finfo *finfo, int rows, int cols, int win_len);
void	set_field_rows(t_finfo *finfo, int rows);
void	set_field_cols(t_finfo *finfo, int cols);
void	set_field_range(t_finfo *finfo, int win_len);

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

void	set_field(t_finfo *finfo, int rows, int cols, int win_len)
{
	(*finfo).rows = rows;
	(*finfo).columns = cols;
	(*finfo).win_len = win_len;
}


void	set_field_rows(t_finfo *finfo, int rows)
{
	(*finfo).rows = rows;
}

void	set_field_cols(t_finfo *finfo, int cols)
{
	(*finfo).columns = cols;
}

void	set_field_range(t_finfo *finfo, int win_len)
{
	(*finfo).win_len = win_len;
}

