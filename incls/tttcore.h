#ifndef TTTCORE_H
# define TTTCORE_H

#include "field.h"
#include "player.h"

// read field
int		is_every_cell_written(t_finfo *finfo, char (*field)[finfo->columns]);
int		is_cell_written(t_finfo *finfo, int cell, char (*field)[finfo->columns]);
// win logic
int		is_won(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int		is_won_in_diagonal(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int		is_won_cols_rows(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int		is_won_in_row(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int		is_won_in_column(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
// field manipulation 2D
void	write_cell(t_finfo *finfo, char sign, int cell, char (*field)[finfo->columns]);
void	delete_cell(t_finfo *finfo, int cell, char (*field)[finfo->columns]);
void	delete_all_cells(t_finfo *finfo, char (*field)[finfo->columns]);
void	init_field(t_finfo *finfo, char (**field)[finfo->columns]);
void	free_field(t_finfo *finfo, char (**field)[finfo->columns]);
// validation
int		is_field_setting_valid(t_finfo *finfo);
int		is_field_valid(t_finfo *finfo);
int		is_range_valid(t_finfo *finfo);
int		is_cell_input_valid(char *inp, t_finfo *finfo);
int		is_cell_in_field(int cell, t_finfo *finfo);
// setup base
void	set_base(t_finfo *finfo, int base);
void	set_base_custom(t_finfo *finfo, int base, char *base_str);
// setup values player
void	set_player(t_player *player, char *name, char mark);
void	set_player_name(t_player *player, char *name);
void	set_player_mark(t_player *player, char mark);
// setup values field_info
void	set_field(t_finfo *finfo, int rows, int cols, int win_len);
void	set_field_rows(t_finfo *finfo, int rows);
void	set_field_cols(t_finfo *finfo, int cols);
void	set_field_range(t_finfo *finfo, int win_len);

# endif
