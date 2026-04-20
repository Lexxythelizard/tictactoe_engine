// --- include ---
#include "../../incls/tttio.h"
#include "../../incls/tttcore.h"
#include "../../incls/print.h"
#include "../../incls/field.h"

// --- prototype ---
void	print_field(t_finfo *finfo, char (*field)[finfo->columns]);
void	put_sep_line_hor(t_finfo *finfo);
void	print_head(t_finfo *finfo);
void	print_round_seperator(void);

// --- DOC ---
// comment

// --- run ---


// --- define ---

void	print_field(t_finfo *finfo, char (*field)[finfo->columns])
{
	int	row;
	int	col;

	row = 0;
	put_sep_line_hor(finfo);
	while (row < (*finfo).rows)
	{
		put_chr(C_SPAC);
		put_chr(C_SEPV);
		col = 0;
		while (col < (*finfo).columns)
		{
			put_chr(C_SPAC);
			put_chr(field[row][col]);
			put_chr(C_SPAC);
			put_chr(C_SEPV);
			col++;
		}
		put_chr(C_NEWL);
		put_sep_line_hor(finfo);
		row++;
	}
	put_chr(C_NEWL);
}

void	put_sep_line_hor(t_finfo *finfo)
{
	int	i;

	i = 0;
	put_chr(C_SPAC);
	while (i < (*finfo).columns)
	{
		put_str(S_SEPH);
		i++;
	}
	put_chr(C_SEPH);
	put_chr(C_NEWL);
}

void	print_head(t_finfo *finfo)
{
	put_nbr_base(FIRST_CELL, (*finfo).base_str);
	put_str(" - ");
	put_nbr_base(((*finfo).rows * (*finfo).columns), (*finfo).base_str);
	put_str(" cells\n");
	put_str("destributed to ");
	put_nbr_base((*finfo).rows, (*finfo).base_str);
	put_str(" rows and ");
	put_nbr_base((*finfo).columns, (*finfo).base_str);
	put_str(" columns\n");
	put_str("\n");
}

void	print_round_seperator(void)
{
	put_str(S_SEPR);
}
