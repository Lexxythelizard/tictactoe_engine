// +++++++++++ IO Convert_str_int +++++++++++++++

// --- include ---
#include <stdlib.h>

// --- prototype ---
int	get_nbr_from_base(char *inp, char *base);
char	*convert_nbr_to_base(int nbr, char *base);
// specific utility
int	get_len_of_number(int nbr, int base);
// import
int	get_str_len(char *str);
int	is_char_in_str(char c, char *str);

// --- DOC ---
/*
TODO:
	- test		is_element_in_arr	: DONE
	- implement	get_nbr_from_base	: DONE
	- test		get_nbr_from_base	: DONE
	- test		*convert_nbr_to_base	: DONE
	- test		get_row_by_num		: DONE
	- test		get_col_by_num		: DONE
*/

// --- run ---


// --- define ---

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
		if (!(is_char_in_str(*inp, base)))
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
	if (nbr < 0)
	{
		out = malloc(len + 2);
		out[len] = '-';
		len = 1;
	}
	else
	{
		out = malloc(len + 1);
		nbr *= (-1);
		len = 0;
	}
	if (out == NULL)
		return (NULL);
	while ((int)(nbr / divisor) <= -len_base)
		divisor *= len_base;
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

// --- specific utility ---

int	get_len_of_number(int nbr, int base)
{
	int len;
	int divisor;

	len = 1;
	divisor = 1;
	if (nbr < 0)
		len++;
	else
		nbr *= (-1);
	while ((int)(nbr / divisor) <= -base)
	{
		divisor *= base;
		len++;
	}
	return (len);
}
