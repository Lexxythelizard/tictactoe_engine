#ifndef PRINT_H
# define PRINT_H

/*
	 x | O | X
	--- --- ---
	   |   |   
	--- --- ---
	   |   | X
*/

# define C_SEPV	('|')
# define C_SEPH	('-')
# define C_ULTI ('+')
# define C_SPAC	(' ')
# define C_NEWL	('\n')
# define S_SEPH	"----"
# define S_ULTI	"++++"

# define ERR_FIELD "field is invalid:\n\tmin lenth is : <s>\n\tmin width is: <s>\n"
# define ERR_LEN "win lentgh is invalid:\n\tmin win lenth is : <s>\n\tand <= min(row, col)\n"

#endif
