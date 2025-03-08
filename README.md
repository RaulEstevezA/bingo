# Bingo Simulator in C

This is a **C** program developed for the "Fundamentos de la Programación" (Fundamentals of Programming) course at **Universitat Oberta de Catalunya (UOC)**. It was created in **November 2004** and aims to simulate a bingo game between two players.

## Project Description
The program automatically generates two bingo cards and simulates the process of drawing random numbers until one (or both) of the players completes their card. Functions are used to print the cards, generate random numbers, and verify the players' matches.

Additionally, the code includes functionality to differentiate compilation based on the operating system:
- **Windows:** Uses `Sleep()` and `cls` for pausing and clearing the screen.
- **Mac/Linux:** Uses `usleep()` and `clear` for the same functionality.

## How It Works
1. The bingo cards are initialized with `-1` values.
2. Numbers are randomly assigned to the cards.
3. The initial state of the cards is displayed.
4. Random numbers are drawn, and if they match the numbers on the card, they are marked.
5. The process continues until a player (or both) achieves 20 matches.
6. The final cards are displayed, and the winner is determined.

## Requirements
To compile and run the program, a **C** compiler like **GCC** is needed:

### Windows
```sh
gcc -o bingo.exe bingo.c
./bingo.exe
```

### Mac/Linux
```sh
gcc -o bingo bingo.c
./bingo
```

## Source Code
The source code is available in this repository and can be executed on **Windows, Mac, and Linux** without additional modifications.

## Video Explanation
You can watch a detailed explanation of the code in the following YouTube video:
[![Video Explanation](https://img.youtube.com/vi/t-Mx-mWwi7g/0.jpg)](https://youtu.be/t-Mx-mWwi7g)

## Author
This project was developed by **[Your Name]** as part of learning structured programming in **C**.

## License
This project is distributed under the **MIT License**, allowing for free use, modification, and distribution for educational and personal purposes.

