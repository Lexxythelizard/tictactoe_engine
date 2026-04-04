// --- include ---
#include <unistd.h>
#include "../incls/meta.h"

// --- prototype ---
int	is_won(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
// import
int	is_won_in_row(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int	is_won_in_column(t_finfo *finfo, char mark, char (*field)[finfo->columns]);
int	is_won_in_diagonal(t_finfo *finfo, char mark, char (*field)[finfo->columns]);

// --- DOC ---
// comment

// --- run ---


// --- define ---

int	is_won(t_finfo *finfo, char mark, char (*field)[finfo->columns])
{
	if (is_won_in_row(finfo, mark, field))
		return (1);
	if (is_won_in_column(finfo, mark, field))
		return (1);
	if (is_won_in_diagonal(finfo, mark, field))
		return (1);
	return (0);
}
