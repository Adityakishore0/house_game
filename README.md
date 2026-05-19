<div align="center">
  <img alt="House Game" src="https://github.com/user-attachments/assets/cd9dcfc3-4232-4fcf-a4f2-7247bc70e56d" width="90%">
</div>

# ***House Game***
<div align="center">

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=flat-square&logo=c%2B%2B)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey?style=flat-square)
![License](https://img.shields.io/badge/license-MIT-green?style=flat-square)
![Status](https://img.shields.io/badge/status-stable-brightgreen?style=flat-square)
![Compiler](https://img.shields.io/badge/compiler-g%2B%2B%20%7C%20clang%2B%2B-orange?style=flat-square)

**A two-player terminal dice board game written in pure C++.**  
No dependencies. No libraries. Runs everywhere.

</div>

---

## Overview

The House Game is a two-player turn-based dice game played entirely in the terminal. One character starts at the center house and can move left or right across a 13-step board. Players compete to push the character to their side's money position to win. The game features a full terminal UI including a splash screen, coin toss, animated dice, live board rendering, and a post-game screen — all built with ANSI escape codes and standard C++ only.

---

## Board Layout

```
$$$  6  5  4  3  2  1  HOME  1  2  3  4  5  6  $$$
 ^                                               ^
 |                                               |
Player A wins (LEFT)              Player B wins (RIGHT)
```

The character `@` starts at `HOME` (position 0). Each player rolls a dice on their turn and moves the character in their assigned direction. The first player to move the character onto or past their `$$$` wins.

---

## Features

- Full terminal UI with ANSI color rendering
- Splash screen with ASCII title art
- Main menu with How To Play section
- Player name entry
- Coin toss to assign directions and decide who goes first
- ASCII dice face display on every roll
- Live board that updates every turn
- Turn counter and position tracker
- Win screen with total turns played
- Play Again, Main Menu, and Quit options after each game
- Zero external dependencies — standard library only
- Compatible with local terminals and online C++ compilers

---

## Requirements

| Requirement | Minimum |
|---|---|
| C++ Standard | C++17 |
| Compiler | g++ / clang++ / MSVC |
| Terminal | Any ANSI-compatible terminal |
| OS | Linux, macOS, Windows (Windows Terminal recommended) |
| Dependencies | None |

---

## Getting Started

### Clone the repository

```bash
git clone https://github.com/your-username/house-game.git
cd house-game
```

### Compile

**Linux / macOS**
```bash
g++ -std=c++17 -o house_game main.cpp
```

**Windows (PowerShell or Windows Terminal)**
```bash
g++ -std=c++17 -o house_game.exe main.cpp
```

**With clang++**
```bash
clang++ -std=c++17 -o house_game main.cpp
```

### Run

**Linux / macOS**
```bash
./house_game
```

**Windows**
```bash
house_game.exe
```

---

## Online Compilers

The game is built to run on online C++ compilers with no modification required.

| Compiler | Supported | Notes |
|---|---|---|
| [OnlineGDB](https://www.onlinegdb.com) | Full | Recommended. Colors and screen clear work correctly |
| [Replit](https://replit.com) | Full | All features work |
| [Programiz](https://www.programiz.com/cpp-programming/online-compiler) | Partial | Colors work, screen clear may vary |
| [JDoodle](https://www.jdoodle.com) | Partial | Colors work, screen clear may not |
| [Ideone](https://ideone.com) | Partial | Input works, colors may not render |

For the best experience online, use **OnlineGDB** and paste the contents of `main.cpp` directly.

---

## How to Play

**1. Coin Toss**

One player calls Heads or Tails. The winner of the toss goes first and is assigned the **Left** side of the board (moving towards `-$$$`). The other player is assigned the **Right** side (moving towards `+$$$`).

**2. Taking Turns**

Players alternate turns. On your turn, press `ENTER` to roll the dice. The dice produces a value from 1 to 6. The character moves that many steps in your direction from its current position.

**3. Winning**

The first player to move the character to or past their `$$$` (position 7 or -7) wins the game.

---

## Project Structure

```
house-game/
├── main.cpp        
├── README.md       
└── .gitignore      
```

---

## .gitignore

```
house_game
house_game.exe
*.o
*.out
```

---

## Roadmap

- [ ] Score tracking across multiple rounds
- [ ] Configurable board length
- [ ] Difficulty mode with a simple AI opponent
- [ ] Sound cues via terminal bell
- [ ] Windows native color API fallback

---

## Contributing

Contributions are welcome. To contribute:

1. Fork the repository
2. Create a new branch: `git checkout -b feature/your-feature`
3. Commit your changes: `git commit -m "Add your feature"`
4. Push to the branch: `git push origin feature/your-feature`
5. Open a pull request

Please keep code clean, commented minimally, and compatible with C++17.

---

## License

This project is licensed under the MIT License.

```
MIT License

Copyright (c) 2025 your-username

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

---

<div align="center">

Built with standard C++. No frameworks. No dependencies. Just code.

</div>
