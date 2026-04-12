#ifndef FIELD_H
# define FIELD_H

# define EMPTY (' ')

# define MIN_LEN (3)
# define MIN_WIDTH (3)
# define MIN_RANGE (3)

# define FIRST_CELL (1)

# define BIN_BASE "01"
# define OCT_BASE "01234567"
# define DEC_BASE "0123456789"
# define DDE_BASE "0123456789AB"
# define HEX_BASE "0123456789ABCDEF"

# define FINFO_ROWS "lenght cells: "
# define FINFO_COLS "width cells : "
# define FINFO_WLEN "win lentgh  : "
# define FINFO_BASE_I "base of     : "
# define FINFO_BASE_S "base        : "


typedef struct s_field_info
{
	int	rows;
	int	columns;
	int	win_len;
	int	base;
	char	*base_str;
} t_finfo;

# endif 
