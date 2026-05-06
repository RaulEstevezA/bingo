# Bingo Simulator in C

[🇪🇸 Leer en español](README_es.md)

## Demo Video

[Watch the demo video](https://youtu.be/t-Mx-mWwi7g)

## Screenshot

<p align="center">
    <img src="img/bingo.png" alt="Bingo simulator screenshot" width="600">
</p>

## Project Description

This is a **C** program developed for the "Fundamentos de la Programación" (Fundamentals of Programming) course at **Universitat Oberta de Catalunya (UOC)**. It simulates a bingo game between two players directly in the terminal.

The program creates two bingo cards, draws random numbers from 0 to 99, marks each player's hits, and finishes when one player completes all 20 numbers on their card. If both players complete their cards on the same draw, the game ends in a tie.

## How It Works

1. Three 100-position arrays are initialized with `-1`: player 1's card, player 2's card, and the drawn-number board.
2. Each player receives 20 random numbers, distributed across the 0-99 range.
3. The initial empty boards and the generated player cards are displayed in the terminal.
4. The program draws random numbers without repeating them.
5. When a drawn number appears on a player's card, it is marked with the ASCII block character.
6. The simulation continues until player 1, player 2, or both players reach 20 hits.
7. The final drawn-number board is displayed and the winner is announced.

## Platform Support

The source code includes small platform-specific sections so the same program can run on different operating systems:

- **Windows:** uses `Sleep()` and `cls`.
- **macOS/Linux:** uses `usleep()` and `clear`.

## Requirements

You only need a C compiler such as **GCC**.

### Windows

```sh
gcc -o Bingo.exe Bingo.c
./Bingo.exe
```

### macOS/Linux

```sh
gcc -o Bingo Bingo.c
./Bingo
```

## Repository Contents

- `Bingo.c`: main source code.
- `img/bingo.png`: screenshot of the program running.
- `README.md`: English documentation.
- `README_es.md`: Spanish documentation.

## Author

Developed by **Raul Estevez** as part of a structured programming exercise in **C**.

## License

No license file is currently included in this repository.
