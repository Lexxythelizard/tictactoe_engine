# Changelog

All relevant changes to this project are recorded in this document.

This project follows **Semantic Versioning** (https://semver.org/).

---

## [1.0.0] – 2025-02-XX
### Added
- Initial implementation of a fully playable TicTacToe game in C.
- 2D playing field (`ROWS x COLUMNS`) with generic board structure.
- `setup_field()` to initialize the playing field.
- `print_field()` for structured ASCII output of the playing field.
- `write_cell()` for write operations on the board.
- `get_location_by_cell_number()` as a central pointer-based utility function.
- Complete move validation:
  - valid cell number
  - prevents overwriting of already occupied fields
  - robust input handling (interception of non-numbers).
- Implementation of a complete game loop:
  - Player change (`X` and `O`)
  - Input → Validation → Writing → Check win/draw → Next round.
- Replay function (`is_willing_to_continue()`).
- Generic, scalable win logic:
  - Utility functions `rl_down`, `rl_right`, `rl_right_up`, `rl_right_down`
  - `is_line_equal()` for any win lengths
  - `is_won()` for generic win checking.


### Fixed
- Fixed a bug that allowed overwriting existing cells.
- Fixed a bug in the win query: incorrect function call (`is_won(field, active_player != 0)` → `is_won(field, active_player)`).
- Input flush problem after `scanf` partially mitigated (buffer emptying added).
- Calculation of cells (indexing) standardized and correctly implemented.

### Changed
- Consistent switch to pointer-based board access via `get_location_by_cell_number()`.
- Game loop structurally improved for better readability and extensibility.
- Various variable names and function inputs standardized.

### Known Issues
- Non-numeric input (letters) may cause incorrect cell selection. 
  Fix planned for v1.1.0


---

## Structure
- `tic_tac_toe.c` – Main program
- `README.md` – Project documentation
- `CHANGELOG.md` – Version history

---

## Notes
Version 1.0.0 forms the stable basis for upcoming features such as:
- Player statistics
- AI opponents (e.g., minimax)
- Undo/redo system
- Colored terminal output
- Dynamic playing field sizes

