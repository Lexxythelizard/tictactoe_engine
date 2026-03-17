#ifndef TTTENGINE_H
# define TTTENGINE_H

#include "meta.h"

// read field
int		is_won_in_diagonal(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int		is_every_cell_written(t_finfo *finfo, char (*field)[finfo->columns]);
int		is_cell_written(t_finfo *finfo, int cell, char (*field)[finfo->columns]);
int		is_won_in_row(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int		is_won_in_column(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
// field manipulation 2D
void	write_cell(t_finfo *finfo, char sign, int cell, char (*field)[finfo->columns]);
void	delete_cell(t_finfo *finfo, int cell, char (*field)[finfo->columns]);
void	delete_all_cells(t_finfo *finfo, char (*field)[finfo->columns]);
void	init_field(t_finfo *finfo, char (**field)[finfo->columns]);
void	free_field(t_finfo *finfo, char (**field)[finfo->columns]);
// validation
int		is_field_valid(t_finfo *finfo);
int		is_range_valid(t_finfo *finfo);
int		is_cell_input_valid(char *inp, t_finfo *finfo);
int		is_cell_in_field(int cell, t_finfo *finfo);
// get user input
char	*get_user_input(char *str);
char	*read_stdin(void);

# endif
