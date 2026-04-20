#ifndef TTTUTILS_H
# define TTTUTILS_H

#include "field.h"

int     	get_row_by_num(int num, t_finfo *finfo);
int     	get_col_by_num(int num, t_finfo *finfo);
int     	get_cell_by_row_col(int row, int col, t_finfo *finfo);
int		is_numeric(char *str);
int		is_element_in_arr(char c, char *str);
int     	get_str_len(char *str);
char	*lxy_strcpy(char *src, char *dest);
int		lxy_strcmp(char *str1, char *str2);
int		get_max(int a, int b);
int		get_min(int a, int b);

# endif
