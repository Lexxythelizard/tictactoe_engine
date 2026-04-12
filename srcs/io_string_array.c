// +++++++++++ IO Convert_str_int +++++++++++++++

// --- include ---
#include <stdlib.h>

// --- prototype ---
char	**create_string_array(char **strs, int n_strs);
void	string_array_append(char ***strs, char *new_str);
char	**create_empty_string_array(void);
void	free_string_array(char **strs);
// specialized utilities 
int		get_len_string_array(char **strs);
// import
int             get_str_len(char *str);
char    *lxy_strcpy(char *scr, char *dest);

// --- DOC ---
/*

*/

// --- define ---

/*

*/

char	**create_string_array(char **strs, int n_strs)
{
	char	**new;
	int		i;

	new = create_empty_string_array();
	i = 0;
	while (i < n_strs)
	{
		string_array_append(&new, strs[i]);
		i++;
	}
	return (new);
}

/*
string_array_append() creates a temporary string array 
allocated using the get_len_str_array()
copies over the pointers of the old strings, append the new string
and NULL-Pointer terminate it

NOTE:
make sure string array is terminated by NULL Pointer
*/

void	string_array_append(char ***strs, char *new_str)
{
	char	**new_strs;
	char	*temp;
	int	len;
	int	i;

	len = get_len_string_array(*strs);
	i = 0;
	new_strs = malloc((len + 2) * sizeof(char *));
	while (i < len)
	{
		new_strs[i] = (*strs)[i];
		i++;
	}
	temp = malloc(get_str_len(new_str));
	new_strs[i] = lxy_strcpy((*strs)[i], new_strs[i]);
	free(temp);
	new_strs[i + 1] = NULL;
	free(*strs);
	*strs = NULL;
	*strs = new_strs;
}

/*
create_empty_string_array() allocates an new string array
and set its first element to NULL

	return:	string array
*/

char	**create_empty_string_array(void)
{
	char **new_array;

	new_array = malloc(1 * sizeof(char *));
	*new_array = NULL;
	return (new_array);
}

/*
free_string_array() loops through the array, freeing every string until it encounters
the terminating NULL-pointer
then freeing the array

NOTE:
string array has to be NULL-pointer terminated
*/

void	free_string_array(char **strs)
{
	int	len;
	int	i;

	len = get_len_string_array(strs);
	i = 0;
	while (i <= len)
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
}

// --- specialized utilities ---

/*
get_len_string_array() counts the strings in array until NULL is encountered

	return:	number of strings
*/

int	get_len_string_array(char **strs)
{
	int	len;

	len = 0;
	while (strs[len] != NULL)
	{
		len++;
	}
	return (len);
}
