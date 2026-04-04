#ifndef META_H
# define META_H

# define TRUE (1)
# define FALSE (0)
# define X ('X')
# define O ('O')
# define EMPTY (' ')
# define P1 "Player 1"
# define P2 "Player 2"

# define MIN_LEN (3)
# define MIN_WIDTH (3)
# define MIN_RANGE (3)

# define FIRST_CELL (1)

# define BIN_BASE "01"
# define OCT_BASE "01234567"
# define DEC_BASE "0123456789"
# define DDE_BASE "0123456789AB"
# define HEX_BASE "0123456789ABCDEF"

typedef struct s_field_info
{
	int	rows;
	int	columns;
	int	win_len;
	int	base;
	char	*base_str;
} t_finfo;

typedef struct s_player
{
	char	*name;
	char	mark;
} t_player;

# endif 
