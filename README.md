# Game Vouvalia
A console-based game inspired by Minesweeper, developed in C.
Reveal safe cells, avoid hidden buffaloes, and clear the board using logic and strategy.

# Preview
   1  2  3  4  5
  ----------------
1| #  #  #  #  #
2| #  1  1  #  #
3| #  .  .  2  #
4| #  #  1  @  #

# Gameplay
The game starts with a hidden grid filled with #.
Your goal is to reveal all safe cells without stepping on a buffalo (@).

# Symbols
| Symbol | Description                 |
| ------ | --------------------------- |
| `#`    | Hidden cell                 |
| `.`    | Empty (no nearby buffaloes) |
| Number | Number of nearby buffaloes  |
| `@`    | Buffalo (mine)              |
| `*`    | Player mark                 |

# Features
Multiple difficulty levels
Random buffalo generation
Minesweeper-like logic
Automatic reveal of empty areas
Coordinate-based input
Console UI with board rendering

# Difficulty Levels
| Level | Description |
| ----- | ----------- |
| 1     | Easy        |
| 2     | Medium      |
| 3     | Hard        |
| 4     | Super Hard  |

Each level increases the buffalo density.

# Build & Run
# Compile
gcc game_vouvalia.c -o game_vouvalia
# Run
./game_vouvalia

# Controls
| Input     | Action                       |
| --------- | ---------------------------- |
| `x,y`     | Reveal cell (example: `3,4`) |
| `x` / `X` | Exit game                    |
| `b`       | Mark a cell as buffalo       |
| `h`       | Hint (experimental feature)  |

# Concepts Practiced
This project was created to practice:
2D arrays
Dynamic memory allocation
Recursion
Game loop design
Randomized board generation
Basic terminal UI

# Known Issues
Some boundary checks need improvement.
Recursive calls could be optimized.
Hint logic is experimental.
Code structure can be further modularized.

# Future Improvements
Better input validation
Save/load game state
Win screen and statistics
Cleaner separation into modules (.h / .c files)
Colorized terminal output
First-move safety logic improvements

