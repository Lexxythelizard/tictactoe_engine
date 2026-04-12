// --- include ---

// --- proto ---
void	put_newlines(int n);
void	put_newline(void);
void	put_spaces(int n);
void	put_space(void);

// import
void	put_chr(char c);

// --- DOC ---
/*
this file contains some extra utils for terminal output:

	- put_newline():	puts one newline
	- put_newlines(n):	puts n newlines
	- put_spaces():		put one space
	- put_spaces(n):	put n spaces
*/

// --- define ---

void	put_newlines(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		put_chr('\n');
		i++;
	}
}

void	put_newline(void)
{
	put_chr('\n');
}

void	put_spaces(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		put_chr(' ');
		i++;
	}
}

void	put_space(void)
{
	put_chr(' ');
}
