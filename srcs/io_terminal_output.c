// --- include ---
#include <unistd.h>

// --- proto ---
void    put_integrate_str_in_str(char *str, char **strs);
void	put_nbr_base(int nbr, char *base);
void	put_nbr_base_edge(char *base);
void	put_chr(char c);
void	put_str(char *str);
//import
int	get_str_len(char *str);

// --- DOC ---
// comment

// --- run ---


// --- define ---

void    put_integrate_str_in_str(char *str, char **strs)
{
	while(*str)
	{
		if ((*str == '<') && (*(str + 1) == 's') && (*(str + 2) == '>'))
		{
			put_str(*strs);
			strs++;
			str += 2;
		}
		else
			put_chr(*str);
		str++;
	}
}

void	put_nbr_base(int nbr, char *base)
{
	int	len;
	int	divisor;

	len = get_str_len(base);
	divisor = 1;
	if (nbr == -2147483648)
	{
		put_nbr_base_edge(base);
		return ;
	}
	if (nbr >= 0)
		nbr *= (-1);
	else
		put_chr('-');
	while ((int)(nbr / divisor) <= -len)
		divisor *= len;
	while (divisor >= len)
	{
		put_chr(base[((int)(nbr / divisor) * (-1))]);
		nbr %= divisor;
		divisor /= len;
	}
	put_chr(base[((int)(nbr / divisor) * (-1))]);
}

void	put_nbr_base_edge(char *base)
{
	int	i;

	i = 0;
	put_chr('-');
	put_chr(base[0]);
	while (i < 31)
	{
		put_chr(base[1]);
		i++;
	}
}

void	put_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	put_chr(char c)
{
	write(1, &c, 1);
}
