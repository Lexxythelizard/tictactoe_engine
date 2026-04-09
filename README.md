# TicTacToe Engine – Version 1.1.0 (C)

A modular, playable and increasingly generic TicTacToe engine written in C.

This project started as my first standalone C game. After completing the 42 Berlin Piscine in February 2026, I returned to the project and began refactoring it into a cleaner, more modular and more extensible architecture with separated core, IO and CLI layers.

Current focus:
- generic board handling
- scalable win detection
- modular project structure
- CLI playability
- configurable cell numbering bases

---

## ✨ Features

### ✔ Playable CLI Prototype
- Player vs Player
- alternating turns
- win and draw detection
- input validation
- playable directly in the terminal

### ✔ Generic Board Configuration
- dynamic board size
- dynamic win length
- not limited to classic 3x3 TicTacToe
- tested with:
  - `3 x 3`, win length `3`
  - `4 x 5`, win length `4`

### ✔ Multiple Cell Numbering Bases
Cells can be addressed in different bases:

- base 2  → `"01"`
- base 8  → `"01234567"`
- base 10 → `"0123456789"`
- base 12 → `"0123456789AB"`
- base 16 → `"0123456789ABCDEF"`

This makes the project more experimental and generic than a standard TicTacToe implementation.

### ✔ Modular Architecture
The project is split into separate areas:

- **core** → game logic, board manipulation, validation, win detection
- **io** → input/output helpers, conversions, terminal interaction
- **ui/cli** → printed game messages and field rendering
- **playable prototype** → first generic playable prototype using the engine

### ✔ Low-Level Memory Handling
- dynamically allocated contiguous 2D field representation
- explicit field initialization and cleanup
- tested with Valgrind during refactoring

---

## 🧠 Technical Focus

This project was built to deepen my understanding of:

- pointer usage in C
- dynamically allocated 2D board handling
- modular architecture and refactoring
- separation of engine logic and interface logic
- input validation and conversion
- scalable win detection for variable board sizes

The project intentionally keeps its low-level toolset small and primarily relies on:

- `write()`
- `malloc()`
- `free()`

---

## 📁 Project Structure

```text
tictactoe/
├── ttt_lib/
│   ├── libtttcore.a
│   ├── libtttio.a
│   └── libtttutils.a
├── incls/
│   ├── field.h
│   ├── print.h
│   ├── tttcore.h
│   ├── tttio.h
│   └── tttutils.h
├── srcs/
│   ├── core_field_manipulation.c
│   ├── core_is_won.c
│   ├── core_won_row_col.c
│   ├── core_won_diagonal.c
│   ├── core_read_field.c
│   ├── core_validation.c
│   ├── core_setup_values.c
│   ├── core_utils.c
│   ├── io_terminal_output.c
│   ├── io_convert_str_int.c
│   ├── io_integrate_str_in_str.c
│   ├── io_user_input.c
│   └── io_utils.c
├── ui/
│   ├── cli/
│   │   ├── print_error_messages.c
│   │   ├── print_game_messages.c
│   │   └── print_field.c
│   └── gui/
├── playable_prototype/
│   └── first_prototype.c
├── play/
├── Makefile
├── README.md
└── LICENSE
```


## 🧠 Technical Notes

### 🔹 Generic addressing via pointers
Cells are accessed via:

```
char *get_location_by_cell_number(char field[][COLUMNS], int cell_number)
```
This enables:
- clean read/write operations
- generic win detection
- pointer-based traversal of the board


## ▶ How to Compile

**From the terminal:**

```
cc -Wall -Wextra -Werror ./playable_prototype/first_prototype.c ./ui/cli/print_field.c \
./ui/cli/print_error_messages.c ./ui/cli/print_game_messages.c \
-L ./ttt_lib/ -l tttcore -l tttio -l tttutils -o ./play/prototype
```
--> requieres: libraries:
    *create libraries with:*

```
make createlib
```
*creates the directory ttt_lib and creates libraries 'tttcore.a' 'tttio.a' 'tttutils.a'*

    *or*

```
make
```
*since createlib is the first target*

--> alternative use:

```
make first_prototype
```
*creates libraries
creates dir play and compiles the code using the cli command above**


**Run with:**
```
./play/prototype <rows> <columns> <win_len> <base>
```
Examples:
```
./play/prototype 3 3 3 10
./play/prototype 4 5 4 12
```

## ▶ Example Gameplay

**classic**
```
New round:
Player 1got: X
Player 2got: O

1 - 9 cells
destributed to 3 rows and 3 columns

 -------------
 |   |   |   |
 -------------
 |   |   |   |
 -------------
 |   |   |   |
 -------------
Player 1's turn.

    ...

1 - 9 cells
destributed to 3 rows and 3 columns

 -------------
 | X |   | O |
 -------------
 | O | O |   |
 -------------
 | X |   | X |
 -------------
Player 1's turn. 

```

**extended**
```
New round:
Player 1got: X
Player 2got: O

1 - 10100 cells
destributed to 100 rows and 101 columns

 ---------------------
 |   |   |   |   |   |
 ---------------------
 |   |   |   |   |   |
 ---------------------
 |   |   |   |   |   |
 ---------------------
 |   |   |   |   |   |
 ---------------------
Player 1's turn. 

    ...

write cell: 10000
 ---------------------
 | X | O | X | O | X |
 ---------------------
 | O | X | O | X | O |
 ---------------------
 | X | O | X | O | X |
 ---------------------
 | O |   |   |   |   |
 ---------------------
Player 2 has won!
Round finished!

```

## 🚧 Planned Extensions

- improved README and testing documentation
- more generic player configuration
- more than two players
- variable marks and player names
- Ultimate TicTacToe as an extension layer
- GUI for 2D play
- later exploration of 3D logic and UI.


---

## 🦎 Author

Lexxy

---

Learning C since November 2025 • Version 1 of TicTacToe
