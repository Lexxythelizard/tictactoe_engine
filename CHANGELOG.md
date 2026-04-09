# Changelog

All relevant changes to this project are recorded in this document.

This project follows **Semantic Versioning**.

---

## [1.1.0] – 2026-04-08

## [1.1.0] – 2026-04-08

### Added
- Added custom static libraries:
  - `libtttcore.a`
  - `libtttio.a`
  - `libtttutils.a`
- Added dedicated header files for modular project structure:
  - `field.h`
  - `print.h`
  - `tttcore.h`
  - `tttio.h`
  - `tttutils.h`
- Added a Makefile-based build workflow for compiling libraries and playable targets.
- Added a first generic CLI-playable prototype (`first_prototype.c`).
- Added support for dynamic board dimensions.
- Added support for dynamic win length.
- Added support for configurable cell numbering bases:
  - base 2
  - base 8
  - base 10
  - base 12
  - base 16
- Added a dynamically allocated contiguous 2D char array representation for the playing field.
- Added separated win-detection functions for:
  - rows / columns
  - diagonals
- Added dedicated validation functions for:
  - field dimensions
  - win-length range
  - cell input
  - cell bounds
- Added memory-managed field initialization and cleanup:
  - `init_field()`
  - `free_field()`

### Changed
- Reworked the project from a single standalone C file into a modular multi-file structure.
- Introduced a library-and-header-based architecture instead of a single-file implementation.
- Separated responsibilities more clearly between:
  - board manipulation
  - win detection
  - validation
  - setup/configuration
  - terminal input/output
  - CLI rendering/messages
- Replaced the original fixed-size-only implementation with a more generic field model.
- Improved input handling and conversion workflow for user-entered cell values.
- Improved readability and maintainability through clearer source separation and library usage.
- Updated project architecture to support future extensions such as:
  - Ultimate TicTacToe
  - GUI frontend
  - more generic player and mark handling

### Fixed
- Fixed memory-management issues during input / conversion flow.
- Fixed at least one confirmed heap leak detected with Valgrind in the prototype flow.
- Fixed build and linker issues related to:
  - duplicate utility definitions
  - incorrect library composition
  - Makefile path / line-continuation mistakes
- Improved stability of the playable prototype for tested configurations.

### Tested
- Confirmed playable with:
  - `3 x 3`, win length `3`
  - `4 x 5`, win length `4`
- Tested with multiple bases:
  - `2`
  - `8`
  - `10`
  - `12`
  - `16`

### Notes
Version `1.1.0` is the first refactored and architecture-oriented version of the project.
It marks the transition from an initial standalone learning project to a more extensible TicTacToe engine prototype.

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
  - robust input handling (interception of non-numbers)
- Implementation of a complete game loop:
  - player change (`X` and `O`)
  - input → validation → writing → check win/draw → next round
- Replay function (`is_willing_to_continue()`).
- Generic, scalable win logic:
  - utility functions `rl_down`, `rl_right`, `rl_right_up`, `rl_right_down`
  - `is_line_equal()` for any win lengths
  - `is_won()` for generic win checking

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
- `README.md` – Project documentation
- `CHANGELOG.md` – Version history

---

## Notes
Version `1.0.0` forms the stable basis for the later refactored engine-oriented prototype introduced in `1.1.0`.
