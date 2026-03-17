// --- include ---
#include <unistd.h>
#include <stdlib.h>

// --- prototype ---
int	is_element_in_arr(char c, char *str);
int	get_nbr_from_base(char *inp, char *base);
char	*convert_nbr_to_base(int nbr, char *base);
char	*lxy_strcpy(char *src, char *dest);
// import
int     get_str_len(char *str);
int     get_len_of_number(int nbr, int base);

// --- DOC ---
/*
TODO:
	- test		is_element_in_arr	: DONE
	- implement	get_nbr_from_base	: DONE
	- test		get_nbr_from_base	: DONE
*/

// --- run ---


// --- define ---
int	is_element_in_arr(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

/*
get_nbr_from_base() uses lenght of str base as base to convert.
both arguments need to be checked before (see validation)
guard: if element not in base: return 0
*/

int	get_nbr_from_base(char *inp, char *base)
{
	int	i;
	int	len_base;
	int	nbr;

	nbr = 0;
	len_base = 0;
	while (base[len_base])
	{
		len_base++;
	}
	while (*inp)
	{
		i = 0;
		if (!(is_element_in_arr(*inp, base)))
			return (0);
		while ((base[i]) && (base[i] != *inp))
		{
			i++;
		}
		nbr = nbr * len_base + i;
		inp++;
	}
	return (nbr);
}

char	*convert_nbr_to_base(int nbr, char *base)
{
	int	divisor;
	int	len_base;
	int	len;
	char	*out;
	
	divisor = 1;
	len_base = get_str_len(base);
	len = get_len_of_number(nbr, len_base);
	if (nbr > 0)
		nbr *= (-1);
	while ((int)(nbr / divisor) <= -len_base)
		divisor *= len_base;
	out = malloc(len + 1);
	if (out == NULL)
		return (NULL);
	len = 0;
	if (nbr < 0)
	{
		out[len] = '-';
		len++;
	}
	while (divisor >= len_base)
	{
		out[len] = base[(int)(nbr / divisor) * (-1)];
		nbr %= divisor;
		divisor /= len_base;
		len++;
	}
	out[len] = base[(int)(nbr / divisor) * (-1)];
	out[len + 1] = '\0';
	return (out);
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
