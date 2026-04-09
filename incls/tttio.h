#ifndef TTTIO_H
# define TTTIO_H

// string manipulation
char    *integrate_in_str(char *str, char **strs);
// get user input
char	*get_user_input(char *str);
char	*read_stdin(void);
// Convert_str_int
int     get_nbr_from_base(char *inp, char *base);
char    *convert_nbr_to_base(int nbr, char *base);
// terminal output
void	put_integrate_str_in_str(char *str, char **strs);
void	put_nbr_base(int nbr, char *base);
void	put_chr(char c);
void	put_str(char *str);

# endif
