#ifndef TTTIO_H
# define TTTIO_H

#include "meta.h"

// string manipulation
char    *integrate_in_str(char *str, char **strs);
// get user input
char	*get_user_input(char *str);
char	*read_stdin(void);
// Convert_str_int
int     get_nbr_from_base(char *inp, char *base);
char    *convert_nbr_to_base(int nbr, char *base);

# endif
