// --- include ---
#include <unistd.h>
#include "../incls/meta.h"
#include "../incls/print.h"

// --- prototype ---
void	print_field(t_finfo *finfo, char (*field)[finfo->columns]);
void	put_sep_line_hor(t_finfo *finfo);
void	print_head(t_finfo *finfo);
//import
void	put_nbr_base(int nbr, char *base);
void	put_nbr_base_edge(int nbr, char *base);
void	put_chr(char c);
void	put_str(char *str);

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
		put_str(" |");
		col = 0;
		while (col < (*finfo).columns)
		{
			put_chr(' ');
			put_chr(field[row][col]);
			put_str(" |");
			col++;
		}
		put_chr('\n');
		put_sep_line_hor(finfo);
		row++;
	}
}

void	put_sep_line_hor(t_finfo *finfo)
{
	int	i;

	i = 0;
	put_chr(' ');
	while (i < (*finfo).columns)
	{
		put_str("----");
		i++;
	}
	put_str("-\n");
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
