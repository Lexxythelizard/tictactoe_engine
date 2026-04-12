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
// string array
char	**create_string_array(char **strs, int n_strs);
void	string_array_append(char ***strs, char *new_str);
char	**create_empty_string_array(void);
void	free_string_array(char **strs);
// terminal output
void	put_integrate_str_in_str(char *str, char **strs);
void	put_nbr_base(int nbr, char *base);
void	put_chr(char c);
void	put_str(char *str);
// terminal output utils
void	put_newlines(int n);
void	put_newline(void);
void	put_spaces(int n);
void	put_space(void);

# endif
