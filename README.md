# TicTacToe – Version 1 (C)

A simple, fully playable TicTacToe game written in C.  
Built as a learning project focusing on:

- pointer arithmetic  
- handling 2D arrays generically  
- modular design and function separation  
- input validation  
- scalable win-detection utilities  

This is **Version 1** — the first complete, playable implementation.

---

## ✨ Features (v1)

### ✔ Fully playable TicTacToe
- Player vs Player  
- Alternating turns (`X` and `O`)  
- Win and draw detection  
- Replay option  

### ✔ Stable input handling
- Rejects invalid numbers  
- Rejects non-numeric input  
- Rejects overwriting cells  

### ✔ Generic, scalable logic
- `ROWS`, `COLUMNS` and `WIN_LEN` can be changed easily  
- Board operations implemented via pointer utilities  
- Win detection handles all 4 directions:
  - vertical (`↓`)
  - horizontal (`→`)
  - diagonal (`↗`)
  - diagonal (`↘`)

### ✔ Clear modular architecture
Functions include:

- `setup_field`
- `write_cell`
- `is_every_cell_written`
- `is_cell_written`
- `get_location_by_cell_number`
- Win utilities (`rl_down`, `rl_right`, …)
- `print_field`
- `get_cell_input`
- `is_willing_to_continue`

---

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


### 🔹Win detection
Implemented with directional "read line" utilities:
```
rl_down()
rl_right()
rl_right_up()
rl_right_down()
```

*Each builds a temporary line[] of size WIN_LEN, then:*

```
is_line_equal(line, sign)
```

Verifies whether a player has won.

## ▶ How to Compile

From the terminal:

```
gcc tic_tac_toe.c -o tic_tac_toe
```

Run with:
```
./tic_tac_toe
```

## ▶ Example Gameplay

"""
Player 1 got: X
Player 2 got: O


 X |   |  
-----------
 O | X |  
-----------
   |   | O

Player: X 's turn
Please enter cell number:



"""

## 📁 Project Structure
.
├── tic_tac_toe.c
└── README.md

---

## 🦎 Author

Lexxy

---

Learning C since November 2025 • Version 1 of TicTacToe
