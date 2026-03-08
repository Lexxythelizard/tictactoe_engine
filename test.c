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
int	is_element_in_arr(char c, char *str);
int	get_nbr_from_base(char *inp, char *base);
int	get_row_by_num(int num, t_finfo *finfo);
int	get_col_by_num(int num, t_finfo *finfo);
int	get_cell_by_row_col(int row, int col, t_finfo *finfo);
void	write_cell(t_finfo *finfo, char sign, int cell, char (*field)[finfo->columns]);
void	delete_cell(t_finfo *finfo, int cell, char (*field)[finfo->columns]);
void	delete_all_cells(t_finfo *finfo, char (*field)[finfo->columns]);
void	init_field(t_finfo *finfo, char (**field)[finfo->columns]);
void	free_field(t_finfo *finfo, char (**field)[finfo->columns]);
void	print_memory_arr(t_finfo *finfo, char (*field)[finfo->columns]);
void	print_field_arr(t_finfo *finfo, char (*field)[finfo->columns]);

// --- DOC ---
// comment

// --- run ---
int	main(int argc, char **argv)
{
	t_finfo	finfo;
	char	*test_inp;
	int	temp;
	char	(*field)[finfo.columns];

	if (argc == 6)
	{
		test_inp = argv[5];
		finfo.rows = atoi(argv[1]);
		finfo.columns = atoi(argv[2]);
		finfo.win_len = atoi(argv[3]);
		finfo.base = atoi(argv[4]);
		printf("\n---the stats---\n");
		printf("test: rows: %d\n", finfo.rows);
		printf("test: columns: %d\n", finfo.columns);
		printf("test: win len: %d\n", finfo.win_len);
		printf("test: base: %d\n", finfo.base);
		printf("\n---the validation functions---\n");
		printf("test: field valid: %d\n", is_field_valid(&finfo));
		printf("test: win len valid: %d\n", is_range_valid(&finfo));
		printf("test: cell input valid base %s: %d\n", DEC_BASE, is_cell_input_valid(test_inp, &finfo));
		printf("test: cell %d in field: %d\n", 3, is_cell_in_field(3, &finfo));
		printf("\n---get number from base---\n");
		printf("test: inp: %s from %s: %d\n", test_inp, BIN_BASE, get_nbr_from_base(test_inp, BIN_BASE));
		printf("test: inp: %s from %s: %d\n", test_inp, OCT_BASE, get_nbr_from_base(test_inp, OCT_BASE));
		printf("test: inp: %s from %s: %d\n", test_inp, DEC_BASE, get_nbr_from_base(test_inp, DEC_BASE));
		printf("test: inp: %s from %s: %d\n", test_inp, DDE_BASE, get_nbr_from_base(test_inp, DDE_BASE));
		printf("test: inp: %s from %s: %d\n", test_inp, HEX_BASE, get_nbr_from_base(test_inp, HEX_BASE));
		/*
		printf("\n---the cell selection validation function---\n");
		printf("test: inp: %s in arr %s: %d\n", test_inp, BIN_BASE, is_cell_input_valid(*test_inp, BIN_BASE));
		printf("test: inp: %s in arr %s: %d\n", test_inp, OCT_BASE, is_cell_input_valid(*test_inp, OCT_BASE));
		printf("test: inp: %s in arr %s: %d\n", test_inp, DEC_BASE, is_cell_input_valid(*test_inp, DEC_BASE));
		printf("test: inp: %s in arr %s: %d\n", test_inp, DDE_BASE, is_cell_input_valid(*test_inp, DDE_BASE));
		printf("test: inp: %s in arr %s: %d\n", test_inp, HEX_BASE, is_cell_input_valid(*test_inp, HEX_BASE));
		*/
		printf("\n---get row and col by cell---\n");
		temp = get_nbr_from_base(test_inp, BIN_BASE);
		printf("test: from %s: got: %d --> row: %d col: %d\n", BIN_BASE, temp, get_row_by_num(temp, &finfo), get_col_by_num(temp, &finfo));
		temp = get_nbr_from_base(test_inp, OCT_BASE);
		printf("test: from %s: got: %d --> row: %d col: %d\n", OCT_BASE, temp, get_row_by_num(temp, &finfo), get_col_by_num(temp, &finfo));
		temp = get_nbr_from_base(test_inp, DEC_BASE);
		printf("test: from %s: got: %d --> row: %d col: %d\n", DEC_BASE, temp, get_row_by_num(temp, &finfo), get_col_by_num(temp, &finfo));
		temp = get_nbr_from_base(test_inp, DDE_BASE);
		printf("test: from %s: got: %d --> row: %d col: %d\n", DDE_BASE, temp, get_row_by_num(temp, &finfo), get_col_by_num(temp, &finfo));
		temp = get_nbr_from_base(test_inp, HEX_BASE);
		printf("test: from %s: got: %d --> row: %d col: %d\n", HEX_BASE, temp, get_row_by_num(temp, &finfo), get_col_by_num(temp, &finfo));
		printf("\n---test field manipulation---\n");
		printf("init field\n");
		init_field(&finfo, &field);
		printf("write cell\n");
		write_cell(&finfo, 'X', FIRST_CELL, field);
		printf("delete cell\n");
		delete_cell(&finfo, FIRST_CELL, field);
		printf("free field\n");
		free_field(&finfo, &field);
		printf("DONE\n");
		
		printf("init new field\n");
		init_field(&finfo, &field);
		print_field_arr(&finfo, field);
		printf("write cell\n");
		write_cell(&finfo, 'X', FIRST_CELL, field);
		print_field_arr(&finfo, field);
		printf("delete cell\n");
		delete_cell(&finfo, FIRST_CELL, field);
		print_field_arr(&finfo, field);
		print_memory_arr(&finfo, field);
		printf("free new field\n");
		free_field(&finfo, &field);
		printf("DONE\n");
		
	}
	else
		printf("need four arguments");
	return (0);
}

// --- define ---


