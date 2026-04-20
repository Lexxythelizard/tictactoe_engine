// --- include ---
#include "../incls/field.h"
#include "../incls/player.h"

// --- prototype ---
void	set_base(t_finfo *finfo, int base);
void	set_base_custom(t_finfo *finfo, int base, char *base_str);

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

void	set_base(t_finfo *finfo, int base)
{
	(*finfo).base = base;
	if (base == 2)
		(*finfo).base_str = BIN_BASE;
	else if (base == 8)
		(*finfo).base_str = OCT_BASE;
	else if (base == 10)
		(*finfo).base_str = DEC_BASE;
	else if (base == 12)
		(*finfo).base_str = DDE_BASE;
	else if (base == 16)
		(*finfo).base_str = HEX_BASE;
	else
	{
		(*finfo).base = 10;
		(*finfo).base_str = DEC_BASE;
	}
}

void	set_base_custom(t_finfo *finfo, int base, char *base_str)
{
	(*finfo).base = base;
	(*finfo).base_str = base_str;
}
