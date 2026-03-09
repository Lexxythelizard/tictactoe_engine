// --- include ---
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./incls/meta.h"

// --- prototype ---
int	is_field_valid(t_finfo *finfo);
int	is_range_valid(t_finfo *finfo);
int	is_cell_input_valid(char *inp, t_finfo *finfo);
int	is_cell_in_field(int cell, t_finfo *finfo);
void	write_cell(t_finfo *finfo, char sign, int cell, char (*field)[finfo->columns]);
void	delete_all_cells(t_finfo *finfo, char (*field)[finfo->columns]);
void	init_field(t_finfo *finfo, char (**field)[finfo->columns]);
void	free_field(t_finfo *finfo, char (**field)[finfo->columns]);
void	print_field_test(t_finfo *finfo, char (*field)[finfo->columns]);

// --- DOC ---
// comment

// --- run ---
int	main(int argc, char **argv)
{
	t_finfo	finfo;
	char	*test_inp;
	int	temp;
	char	(*field)[finfo.columns];

	if (argc >= 5)
	{
		finfo.rows = atoi(argv[1]);
		finfo.columns = atoi(argv[2]);
		finfo.win_len = atoi(argv[3]);
		finfo.base = atoi(argv[4]);
		i = 5;
		printf("\n---the stats---\n");
		printf("test: rows: %d\n", finfo.rows);
		printf("test: columns: %d\n", finfo.columns);
		printf("test: win len: %d\n", finfo.win_len);
		printf("test: base: %d\n", finfo.base);
		if ((!(is_field_valid(&finfo))) || (!(is_range_valid(&finfo))))
		{
			printf("\nunvalid range, or field\n");
			return (0);
		}	
		printf("\ninit field\n");
		init_field(&finfo, &field);
		while (i < argc)
		{
			if (is_cell_in_field(atoi(argv[i]), &finfo))
				write_cell(&finfo, 'X', atoi(argv[i]), field);
			else
				printf("%d is not in field\n", atoi(argv[i]));
			i++;
		}
		// print field
		print_field_test(&finfo, field);
		// run tests:
		// is won row, is won column, ... diaggonals..
		free_field(&finfo, &field);
		printf("DONE\n");
		
	}
	else
		printf("need four arguments");
	return (0);
}
