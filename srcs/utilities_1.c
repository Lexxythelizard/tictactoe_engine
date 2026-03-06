// --- include ---
#include <unistd.h>

// --- prototype ---
int	is_element_in_arr(char c, char *str);
int	get_nbr_from_base(char *inp, char *base);

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
