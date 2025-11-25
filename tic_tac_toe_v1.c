#include <stdio.h>

#define ROWS 3
#define COLUMNS 3
#define WIN_LEN 3

//picture the field:

	//  X | X | O  # field will be a 2D - Array
	// ----------- # every Cell could have either:
	//  O |   |    # - 'X'
	// ----------- # - 'O'
	//  X |   |    # - ' '

//prototypes

void setup_field(char field_arr[][COLUMNS]);
void write_cell(int cell, char field_arr[][COLUMNS], char sign);
int is_every_cell_written(char field_arr[][COLUMNS]);
int is_cell_input_valid(void);

int is_won(char field_arr[][COLUMNS], char sign);					//checks if won by using following func
int is_line_equal(char line[], char sign);						//compares if every sign in line is sign
											//	--> returns 0 / 1
void rl_down(char line[], char (*ptr_row)[COLUMNS], int column);
void rl_right(char line[], char *ptr_column);
void rl_right_up(char line[], char (*ptr_row)[COLUMNS], int start_column);
void rl_right_down(char line[], char (*ptr_row)[COLUMNS], int start_column);

// main

int main(void) {

	//field

	char field[ROWS][COLUMNS];
	int test_n;			//to test ;)

	//first code
	setup_field(field);

	//test
	write_cell(1, field, 'X');
	write_cell(5, field, 'X');
	write_cell(9, field, 'X');
	if (is_won(field, 'O') != 1) {
		printf("O has not won!\n\n");
	}
	if (is_won(field, 'X') == 1) {
		printf("X has won!\n\n");
	}
	printf("now write every cell iterativly and check the availabillity: \n\n");
	for (test_n = 1; test_n <= ROWS * COLUMNS; test_n++) {
		printf("write cell %d:\n", test_n);
		write_cell(test_n, field, 'T');
		if (is_every_cell_written(field) != 1) {
			printf("still cells available.\n\n");
		}
		else {
			printf("every cell is written\n");
		}
	}
	return 0;
}

void setup_field(char field_arr[][COLUMNS]) {

	//code

	int i;
	int j;

	for (i = 0; i < ROWS; i++) {

		for (j = 0; j < COLUMNS; j++) {

			field_arr[i][j] = ' ';
		}
	}
	return;
}

void write_cell(int cell, char field_arr[][COLUMNS], char sign) {
	//input should be 1 <= cell <= 9
	//fallback before function is called
	int row;
	int column;
	//recconing
	row = (cell - 1) / COLUMNS;
	column = cell - (1 + COLUMNS * row);

	field_arr[row][column] = sign;

	return;
}

int is_every_cell_written(char field_arr[][COLUMNS]) {

	int i;
	int j;
	int all_written = 1;
	for (i = 0 ; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			if (field_arr[i][j] == ' ') {
				all_written = 0;
				break;
			}
		}
		if (all_written == 0) {
			break;
		}
	}
	return all_written;
}

int is_cell_input_valid(void) {
	int input;
	int valid = 1;
	printf("pleas enter cell number: ");
	scanf(" %d", &input);
	if (input < 1 || (ROWS * COLUMNS) < input) {
		valid = 0;
	}
	return valid;
}

//define the win conditions

int is_won(char field_arr[][COLUMNS], char sign) {
	//checks an generic field

	int won = 0;

	char line[WIN_LEN];
	int row;
	int column;

	for (row = 0; row < ROWS; row++) {
		for (column = 0; column < COLUMNS; column++) {
			//if possible read and check line downwards
			if (row <= ROWS - WIN_LEN) {
				rl_down(line, &(field_arr[row]), column);
				if (is_line_equal(line, sign)) {
					won = 1;
					break;
				}
			}
			//if possible read and check line rightwards
			if (column <= COLUMNS - WIN_LEN) {
				rl_right(line, &(field_arr[row][column]));
				if (is_line_equal(line, sign)) {
					won = 1;
					break;
				}
			}
			//if possible read and check line diagonal to upper right
			if (row >= WIN_LEN - 1 && column <= COLUMNS - WIN_LEN) {
				rl_right_up(line, &(field_arr[row]), column);
				if (is_line_equal(line, sign)) {
					won = 1;
					break;
				}
			}
			//if possible read and check line diagonal to lower right
			if (row <= ROWS - WIN_LEN && column <= COLUMNS - WIN_LEN) {
				rl_right_down(line, &(field_arr[row]), column);
				if (is_line_equal(line, sign)) {
					won = 1;
					break;
				}
			}
		}
	}
	return won;
}

//define utillity functions

int is_line_equal(char line[], char sign) {
	//just checks if every char in the string is equal to sign.
	//if n signs in a line are needed to win, arr lenght have to be n ;)
	int equal = 1;
	int i;
	for (i = 0; i < WIN_LEN; i++) {
		if (line[i] != sign) {
			equal = 0;
			break;
		}
	}
	return equal;
}

//utillity: read_line 'rl' {down, right, right_up, right_down}

void rl_down(char line[], char (*ptr_row)[COLUMNS], int column) {

	int i;

	for (i = 0; i < WIN_LEN; i++) {
		line[i] = (*ptr_row)[column];		//ptr_row is pointing on one row :)
		ptr_row++;				//moves one row down
	}
	return;
}

void rl_right(char line[], char *ptr_column) {

	int i;

	for (i = 0; i < WIN_LEN; i++) {
		line[i] = *ptr_column;			//referents one element in the aray
		ptr_column++;				//moves one column further right
	}
	return;
}

void rl_right_up(char line[], char (*ptr_row)[COLUMNS], int start_column) {

	int i;

	for (i = 0; i < WIN_LEN; i++) {			//decrements because moving up
		line[i] = (*ptr_row)[start_column];
		start_column++;				//move one column right
		ptr_row--;				//moves one row up
	}
	return;
}

void rl_right_down(char line[], char (*ptr_row)[COLUMNS], int start_column) {

	int i;

	for(i = 0; i < WIN_LEN; i++) {
		line[i] = (*ptr_row)[start_column];
		start_column++;				//moves one column right
		ptr_row++;				//moves one row down
	}
	return;
}
