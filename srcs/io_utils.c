// +++++++++++ IO Utilities +++++++++++++++

// --- include ---
int	is_numeric(char *str);
int	is_char_in_str(char c, char *str);
int	get_str_len(char *str);
char	*lxy_strcpy(char *src, char *dest);

// --- DOC ---
/*
sniggle
*/

// --- define ---

int	is_numeric(char *str)
{
	if (!(*str))
		return (0);
	while (*str)
	{
		if ((*str <= '0') || (*str >= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	is_char_in_str(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*lxy_strcpy(char *src, char *dest)
{
	char	*new;

	new = dest;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (new);
}
