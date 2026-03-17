// --- include ---
#include <unistd.h>
#include <stdlib.h>
#include "../incls/meta.h"

// --- prototype ---
char	*get_user_input(char *str);
char	*read_stdin(void);
void	append_str(char **str, char c);
//import
int		get_str_len(char *str);
char	*lxy_strcpy(char *scr, char *dest);
// --- DOC ---
// comment

// --- run ---

// --- define ---
char	*get_user_input(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return read_stdin();
}

char	*read_stdin(void)
{
	char	*input;
	char	c;

	c = 0;
	input = malloc(1);
	input[0] = c;	
	while (TRUE)
	{
		read(0, &c, 1);
		if (c == 10)
			break;
		
		append_str(&input, c);
	}
	return (input);
}

void	append_str(char **str, char c)
{
	char	*temp;

	temp = malloc(get_str_len(*str) + 2);
	temp = lxy_strcpy(*str, temp);
	temp[get_str_len(*str)] = c;
	temp[get_str_len(*str) + 1] = '\0';
	free(*str);
	*str = NULL;
	*str = temp;
}

