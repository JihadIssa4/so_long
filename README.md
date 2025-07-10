# so_long

`so_long` is a graphical project from the 42 curriculum that involves building a simple 2D game using the **MiniLibX** graphics library. The player must navigate through a map, collect all the collectibles, and reach the exit to win.

## 🕹️ Game Overview

You play as a character placed on a map filled with:
- `1`: Walls  
- `0`: Floor  
- `C`: Collectibles  
- `E`: Exit  
- `P`: Player starting position  

The objective is to collect all `C` items and reach the `E` tile to win.

## 🔧 Features

- Reads and validates `.ber` map files.
- Renders 2D maps using `.xpm` images.
- Displays the number of moves made.
- Handles movement with **WASD** or **arrow keys**.
- Game exits gracefully with the ESC key or window close button.
- Uses **flood fill** to ensure the map is solvable.
- Tracks and displays game state (collected items, steps, win condition).

## 🗂️ Project Structure

.
├── so_long.c
├── map_check.c
├── flood_fill.c
├── game.c
├── game2.c
├── free.c
├── creating_arr.c
├── so_long_utils.c
├── GNL/
│ ├── get_next_line.c
│ └── get_next_line_utils.c
├── printf/
│ └── ft_printf implementation files
├── images/
│ └── .xpm image files for assets
├── maps/
│ └── .ber map files
└── Makefile

perl
Copy
Edit

## 📦 Compilation

Make sure you have **MiniLibX** installed (for Linux use `minilibx-linux`).

```bash
make

🚀 Running the Game

./so_long maps/map.ber

📝 Example Map (map.ber)

1111111
1P0C0E1
1111111

🛠️ Requirements
A valid map must:

Be rectangular.

Be surrounded by walls (1).

Contain exactly one player (P), at least one exit (E) and at least one collectible (C).

Be solvable (player can collect all Cs and reach E).
