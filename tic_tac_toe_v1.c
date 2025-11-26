#include <stdio.h>

#define ROWS 3
#define COLUMNS 3
#define WIN_LEN 3

#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'
#define EMPTY_CELL ' '

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
int is_cell_written(char *ptr_cell);
int is_cell_input_valid(int cell_number);
int get_cell_input(void);

char *get_location_by_cell_number(char field_arr[][COLUMNS], int cell_number);

int is_won(char field_arr[][COLUMNS], char sign);					//checks if won by using following func
int is_line_equal(char line[], char sign);						//compares if every sign in line is sign
											//	--> returns 0 / 1
void rl_down(char line[], char (*ptr_row)[COLUMNS], int column);
void rl_right(char line[], char *ptr_column);
void rl_right_up(char line[], char (*ptr_row)[COLUMNS], int start_column);
void rl_right_down(char line[], char (*ptr_row)[COLUMNS], int start_column);

void print_field(char field_arr[][COLUMNS]);
int is_willing_to_continue(void);

// main

int main(void) {

	//field

	char field[ROWS][COLUMNS];

	int cell_selected = 0;
	char *ptr_recently_selected;
	char active_player = PLAYER_ONE;

	// ------- Game loop -------

	//	print field			\
	//	input cell	\		 \
	//	validate input	 } loop		  \
	//	validate cell	/		   \
	//	write cell			    \___ loop
	//	check if won			    /
	//	check if draw			   /
	//	ask if continue	\ __ loop	  /
	//	validate input	/		 /
	//	switch player			/


	//pre loop
	printf("\nWelcome!\n\n");
	setup_field(field);
	printf("Player 1 got: %c\n", PLAYER_ONE);
	printf("Player 2 got: %c\n\n", PLAYER_TWO);

	//game loop
	while(1) {

		print_field(field);
		printf("Player: %c \'s turn\n", active_player);
		while(1) {
			cell_selected = get_cell_input();
			ptr_recently_selected = get_location_by_cell_number(field, cell_selected);

			if (is_cell_input_valid(cell_selected) == 0) {
				printf("Please type a valid number from 1 to %d", (ROWS * COLUMNS));
			}
			else if (is_cell_written(ptr_recently_selected) != 0) {
				printf("cannot overwrite cell.\n");
			}
			else {
				break;
			}
		}
		write_cell(cell_selected, field, active_player);

		if (is_every_cell_written(field) != 0 || is_won(field, active_player) != 0) {

			(is_won(field, active_player) != 0) ? printf("\nPlayer: %c has won!\n\n", active_player) : printf("\nIt\'s a draw!\n\n");

			if (is_willing_to_continue() != 0) {

				active_player = (active_player != PLAYER_ONE) ? PLAYER_ONE : PLAYER_TWO;
				setup_field(field);
				printf("Player 1 got: %c\n", PLAYER_ONE);
				printf("Player 2 got: %c\n\n", PLAYER_TWO);
			}
			else {
				printf("\nThank You for playing! <3\n\n\tBye.\n\n");
				break;
			}
		}
		else {
			active_player = (active_player != PLAYER_ONE) ? PLAYER_ONE : PLAYER_TWO;
		}
	}
	return 0;
}

void setup_field(char field_arr[][COLUMNS]) {

	int row;
	int column;

	for (row = 0; row < ROWS; row++) {

		for (column = 0; column < COLUMNS; column++) {

			field_arr[row][column] = EMPTY_CELL;
		}
	}
	return;
}

void write_cell(int cell, char field_arr[][COLUMNS], char sign) {
	//input should be 1 <= cell <= ROWS * COLUMNS
	//fallback before function is called
	int row;
	int column;

	row = (cell - 1) / COLUMNS;
	column = cell - (1 + COLUMNS * row);

	field_arr[row][column] = sign;

	return;
}

int is_every_cell_written(char field_arr[][COLUMNS]) {

	int row;
	int column;
	int all_written;

	for (row = 0 ; row < ROWS; row++) {
		for (column = 0; column < COLUMNS; column++) {

			all_written = is_cell_written(&(field_arr[row][column]));
			if (all_written == 0) {
				break;
			}
		}
		if (all_written == 0) {
			break;
		}
	}
	return all_written;
}

int is_cell_written(char *ptr_cell) {

	return (*ptr_cell == EMPTY_CELL) ? 0 : 1;
	}


int is_cell_input_valid(int cell_number) {

	return (cell_number >= 1 && (ROWS * COLUMNS) >= cell_number) ? 1 : 0;
}

int get_cell_input(void) {

	int input;
	char ch;
	printf("\nPlease enter cell number: ");
	scanf(" %d", &input);
	while (ch = getchar() != '\n' && ch != EOF) { }
	return input;
}

char *get_location_by_cell_number(char field_arr[][COLUMNS], int cell_number) {

	int row;
	int column;
	if (is_cell_input_valid(cell_number) != 0) {
		row = (cell_number - 1) / COLUMNS,
		column = cell_number - (1 + COLUMNS * row);
		return &(field_arr[row][column]);
	}
	return NULL;
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

void print_field(char field_arr[][COLUMNS]) {

	int row;
	int column;
	int i;

	printf("\n");
	for (row = 0; row < ROWS ; row++) {

		for (column = 0; column < COLUMNS; column++) {

			printf(" %c ", field_arr[row][column]);
			if (column < (COLUMNS - 1)) {
				printf("|");
			}
		}
		printf("\n");

		if (row < (ROWS - 1)) {

			for (i = 0; i < (3 * (COLUMNS + 1) - 1); i++) {
				printf("-");
			}
			printf("\n");
		}

		if (row == (ROWS - 1)) {
			printf("\n\n\n");
		}
	}
	return;
}

int is_willing_to_continue(void) {

	char answere;
	char ch;
	printf("Do You want to continue?\n");
	printf("Type \'y\' or \'n\'\t: ");
	scanf(" %c", &answere);
	while (ch = getchar() != '\n' && ch != EOF) { }

	return (answere != 'y' && answere != 'n') ? is_willing_to_continue() : (answere == 'y') ? 1 : 0;
}

