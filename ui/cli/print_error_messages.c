// --- include ---
#include <unistd.h>
#include "../../incls/tttio.h"
#include "../../incls/field.h"

// --- proto ---
void	print_to_few_arguments(int argc, int needed);
void	print_unvalid_field(void);
void	print_unvalid_win_len(void);
void	print_unvalid_mark(void);
void	print_cell_not_in_field(t_finfo *finfo, int cell);
void	print_unvalid_input(t_finfo *finfo, char *input);
void	print_cell_already_written(t_finfo *finfo, int cell);

// import
void    print_str_with_vals(char *str, int **vals);
void	put_nbr_base(int nbr, char *base);
void	put_chr(char c);
void	put_str(char *str);
int	get_str_len(char *str);
char    *convert_nbr_to_base(int nbr, char *base);

// --- DOC ---
// comment

// --- run ---


// --- define ---

void	print_to_few_arguments(int argc, int needed)
{
	put_str("wrong amount of arguments:\n");
	put_nbr_base(needed, DEC_BASE);
	put_str(" arguments requiered. ");
	put_nbr_base(argc, DEC_BASE);
	put_str(" arguments given.\n\n");
}

void	print_unvalid_field(void)
{
	put_str("invalid field \n");
	put_str("rows should be at least: ");
	put_nbr_base(MIN_LEN, DEC_BASE);
	put_str("\nrows should be at least: 3");
	put_nbr_base(MIN_WIDTH, DEC_BASE);
	put_chr('\n');
}

void	print_unvalid_win_len(void)
{
	put_str("invalid win length \n");
	put_str("win length should greater or equal to : ");
	put_nbr_base(MIN_RANGE, DEC_BASE);
	put_str("\nand lower or equal to the min possible range in lenght or width\n");
}

void	print_unvalid_mark(void)
{
	put_str("mark seems to be unvalid \n");
	put_str("try ");
	put_chr('X');
	put_str(" or ");
	put_chr('O');
	put_chr('\n');
}

void	print_cell_not_in_field(t_finfo *finfo, int cell)
{
	put_str("cell appears to be outside the field :/ \n");
	put_str("cell ");
	put_nbr_base(cell, (*finfo).base_str);
	//put_str(convert_nbr_to_base(cell, (*finfo).base_str));
	put_str(" field range from cell: ");
	put_nbr_base(FIRST_CELL, (*finfo).base_str);
	//put_str(convert_nbr_to_base(FIRST_CELL, (*finfo).base_str));
	put_str(" to cell: \n");
	put_nbr_base(((*finfo).rows * (*finfo).columns), (*finfo).base_str);
	//put_str(convert_nbr_to_base(((*finfo).rows * (*finfo).columns), (*finfo).base_str));
	put_chr('\n');
}

void	print_unvalid_input(t_finfo *finfo, char *input)
{
	put_str("unvalid input:\n");
	put_str("input:");
	put_str(input);
	put_str(" valid numberbase of field is: ");
	put_str((*finfo).base_str);
	put_chr('\n');
}
void	print_cell_already_written(t_finfo *finfo, int cell)
{
	put_str("cell: ");
	put_nbr_base(cell, (*finfo).base_str);
	//put_str(convert_nbr_to_base(cell, (*finfo).base_str));
	put_str(" is allready written!\n\n");
}

