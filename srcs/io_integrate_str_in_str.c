// --- include ---
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// --- prototype ---
char	*integrate_in_str(char *str, char **strs);
void	write_new_string(char *dest, char *srcs, char **incl, int n);
int	count_valid_integration_expressions(char *str);
int	is_valid_integration_expression(char *expression);
int	get_len_n_strs(char **strs, int n);
//for testing
int	get_str_len(char *str);

// --- DOC ---
/*
TODO:
	- test	integrate_in_str()			: DONE
	- test	write_new_string()			: DONE
	- test	count_valid_integration_expressions()	: DONE
	- test	is_valid_integration_expression()	: DONE
	- test	get_len_n_strs()			: DONE
*/

// --- test ---
int main()
{
	char	*str = "What <s> the <s> say <s> cock";
	char	*new_str;
	int	i = 0;

	new_str = integrate_in_str(str, (char *[]){ "does", "fox", "?", "!" });
	
	while (new_str[i])
	{
		write(1, &new_str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	
	free(new_str);
	return 0;
}

// --- define ---

char	*integrate_in_str(char *str, char **strs)
{
	int	n_strs;
	int	len_new_string;
	char	*new_str;

	n_strs = count_valid_integration_expressions(str);
	len_new_string = 0;
	len_new_string = get_str_len(str) - (n_strs * 3) + get_len_n_strs(strs, n_strs);
	new_str = malloc(len_new_string + 1);
	if (new_str == NULL)
		return (NULL);
	write_new_string(new_str, str, strs, len_new_string);
	return (new_str);
}

/*
write_new_string() gets the pointer to an allready allocated string: dest
and copies Byte by Byte from srcs over
if encounters an integration expression appending the first string of incl
(then moves pointer to next string of incl and
continues after the integration expression of srcs)
limited by size n
*/

void	write_new_string(char *dest, char *srcs, char **incl, int n)
{
	int	i;

	i = 0;
	while ((*srcs) && (i < n))
	{
		if (is_valid_integration_expression(srcs))
		{
			while((*incl) && (**incl) && (i < n))
			{
				*dest = **incl;
				dest++;
				(*incl)++;
				i++;
			}
			srcs += 3;
			incl++;
		}
		else
		{
			*dest = *srcs;
			dest++;
			i++;
			srcs++;
		}
	}
	*dest = '\0';
}

// count appearance of "<s>"

int	count_valid_integration_expressions(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (is_valid_integration_expression(str))
		{
			len++;
			str += 2;
		}
		str++;;
	}
	return (len);
}


// checks for "<s>"


int	is_valid_integration_expression(char *expression)
{
	if ((*expression == '<') && (*(expression + 1) == 's') && 
			(*(expression + 2) == '>'))
		return (1);
	return (0);
}

// counts and adds the length all strings in an array of strings

int	get_len_n_strs(char **strs, int n)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while ((i < n) && (strs[i] != NULL))
	{
		len += get_str_len(strs[i]);
		i++;
	}
	return (len);
}

int get_str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
