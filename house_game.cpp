#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

#define RESET           "\033[0m"
#define BOLD            "\033[1m"
#define BRIGHT_RED      "\033[91m"
#define BRIGHT_GREEN    "\033[92m"
#define BRIGHT_YELLOW   "\033[93m"
#define BRIGHT_CYAN     "\033[96m"
#define BRIGHT_WHITE    "\033[97m"

void clearScreen() {
    cout << "\033[2J\033[H" << flush;
}

void pressEnter() {
    cout << endl << BRIGHT_CYAN << "  [ Press ENTER to continue... ]" << RESET << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printDice(int v) {
    const string d[7][5] = {
        {},
        {"+---------+", "|         |", "|    *    |", "|         |", "+---------+"},
        {"+---------+", "|  *      |", "|         |", "|      *  |", "+---------+"},
        {"+---------+", "|  *      |", "|    *    |", "|      *  |", "+---------+"},
        {"+---------+", "|  *   *  |", "|         |", "|  *   *  |", "+---------+"},
        {"+---------+", "|  *   *  |", "|    *    |", "|  *   *  |", "+---------+"},
        {"+---------+", "|  *   *  |", "|  *   *  |", "|  *   *  |", "+---------+"}
    };
    for (int i = 0; i < 5; i++) {
        cout << "         " << BRIGHT_WHITE << d[v][i] << RESET << endl;
    }
}

void printBoard(int pos) {
    cout << endl << "  ";
    for (int p = -7; p <= 7; p++) {
        if (p == -7 || p == 7) cout << BRIGHT_RED << "+---+" << RESET;
        else if (p == 0)       cout << BRIGHT_CYAN << "+----+" << RESET;
        else                   cout << BRIGHT_WHITE << "+---+" << RESET;
    }
    cout << endl << "  ";
    for (int p = -7; p <= 7; p++) {
        if (p == pos) {
            if (p == -7 || p == 7) cout << BRIGHT_YELLOW << BOLD << "| @ |" << RESET;
            else if (p == 0)       cout << BRIGHT_YELLOW << BOLD << "|  @ |" << RESET;
            else                   cout << BRIGHT_YELLOW << BOLD << "| @ |" << RESET;
        } else {
            if (p == -7)     cout << BRIGHT_RED   << BOLD << "|$$$|" << RESET;
            else if (p == 7) cout << BRIGHT_GREEN  << BOLD << "|$$$|" << RESET;
            else if (p == 0) cout << BRIGHT_CYAN   << "|HOME|" << RESET;
            else             cout << BRIGHT_WHITE   << "|   |" << RESET;
        }
    }
    cout << endl << "  ";
    for (int p = -7; p <= 7; p++) {
        if (p == -7 || p == 7) cout << BRIGHT_RED << "+---+" << RESET;
        else if (p == 0)       cout << BRIGHT_CYAN << "+----+" << RESET;
        else                   cout << BRIGHT_WHITE << "+---+" << RESET;
    }
    cout << endl << "  ";
    for (int p = -7; p <= 7; p++) {
        if (p == -7 || p == 7) cout << BRIGHT_RED << "  $  " << RESET;
        else if (p == 0)       cout << BRIGHT_CYAN << " HOM  " << RESET;
        else                   cout << BRIGHT_WHITE << "  " << abs(p) << "  " << RESET;
    }
    cout << endl << endl;
    cout << "  " << BRIGHT_RED   << BOLD << "<-- A wins (LEFT)"  << RESET;
    cout << "                        ";
    cout << BRIGHT_GREEN << BOLD << "B wins (RIGHT) -->" << RESET << endl << endl;
}

void showSplash() {
    clearScreen();
    cout << endl << endl;
    cout << BRIGHT_YELLOW << BOLD;
    cout << "  +============================================================+" << endl;
    cout << "  |                                                            |" << endl;
    cout << "  |    _____ _   _ _____   _   _  ___  _   _ ____  _____      |" << endl;
    cout << "  |   |_   _| | | | ____| | | | |/ _ \\| | | / ___|| ____|     |" << endl;
    cout << "  |     | | | |_| |  _|   | |_| | | | | | | \\___ \\|  _|       |" << endl;
    cout << "  |     | | |  _  | |___  |  _  | |_| | |_| |___) | |___      |" << endl;
    cout << "  |     |_| |_| |_|_____|  |_| |_|\\___/ \\___/|____/|_____|    |" << endl;
    cout << "  |                                                            |" << endl;
    cout << RESET << BRIGHT_CYAN << BOLD;
    cout << "  |        ____    _    __  __ _____                          |" << endl;
    cout << "  |       / ___|  / \\  |  \\/  | ____|                         |" << endl;
    cout << "  |      | |  _  / _ \\ | |\\/| |  _|                           |" << endl;
    cout << "  |      | |_| |/ ___ \\| |  | | |___                          |" << endl;
    cout << "  |       \\____/_/   \\_\\_|  |_|_____|                         |" << endl;
    cout << "  |                                                            |" << endl;
    cout << RESET << BRIGHT_WHITE;
    cout << "  |              A  Two-Player  Dice  Board  Game             |" << endl;
    cout << "  |                                                            |" << endl;
    cout << "  |   $$$--6--5--4--3--2--1--[HOME]--1--2--3--4--5--6--$$$   |" << endl;
    cout << "  |                                                            |" << endl;
    cout << "  +============================================================+" << endl;
    cout << RESET << endl;
    pressEnter();
}

void showHowToPlay() {
    clearScreen();
    cout << endl;
    cout << BRIGHT_CYAN << BOLD;
    cout << "  +=====================================================+" << endl;
    cout << "  |                  HOW TO PLAY                       |" << endl;
    cout << "  +=====================================================+" << endl;
    cout << RESET << BRIGHT_WHITE;
    cout << "  |                                                     |" << endl;
    cout << "  |  BOARD:                                             |" << endl;
    cout << "  |   $$$-6-5-4-3-2-1-[HOME]-1-2-3-4-5-6-$$$          |" << endl;
    cout << "  |   One character (@) starts at HOME (position 0).   |" << endl;
    cout << "  |                                                     |" << endl;
    cout << "  |  COIN TOSS:                                         |" << endl;
    cout << "  |   One player calls Heads or Tails.                 |" << endl;
    cout << "  |   Toss winner plays the LEFT side (-).             |" << endl;
    cout << "  |   Other player plays the RIGHT side (+).           |" << endl;
    cout << "  |                                                     |" << endl;
    cout << "  |  TURNS:                                             |" << endl;
    cout << "  |   Players alternate rolling the dice (1-6).        |" << endl;
    cout << "  |   Character moves that many steps in the rolling   |" << endl;
    cout << "  |   player's direction from its current position.    |" << endl;
    cout << "  |                                                     |" << endl;
    cout << "  |  WINNING:                                           |" << endl;
    cout << "  |   Push character to YOUR $$$ (step 7) to win!      |" << endl;
    cout << "  |   Left $$$ = LEFT player wins.                     |" << endl;
    cout << "  |   Right $$$ = RIGHT player wins.                   |" << endl;
    cout << "  |                                                     |" << endl;
    cout << "  +=====================================================+" << endl;
    cout << RESET << endl;
    pressEnter();
}

void getNames(string& p1, string& p2) {
    clearScreen();
    cout << endl;
    cout << BRIGHT_CYAN << BOLD;
    cout << "  +====================================+" << endl;
    cout << "  |           PLAYER SETUP             |" << endl;
    cout << "  +====================================+" << endl;
    cout << RESET << endl;
    cout << "  " << BRIGHT_RED << "Player 1" << BRIGHT_WHITE << " - Enter name: " << RESET;
    getline(cin, p1);
    if (p1.empty()) p1 = "Player 1";
    cout << "  " << BRIGHT_GREEN << "Player 2" << BRIGHT_WHITE << " - Enter name: " << RESET;
    getline(cin, p2);
    if (p2.empty()) p2 = "Player 2";
    cout << endl;
    cout << "  " << BRIGHT_YELLOW << BOLD << "Welcome " << BRIGHT_RED << p1
         << BRIGHT_YELLOW << " and " << BRIGHT_GREEN << p2 << BRIGHT_YELLOW << "!" << RESET << endl;
    pressEnter();
}

void showStatus(const string& curPlayer, const string& curColor,
                const string& leftPlayer, const string& rightPlayer,
                int pos, int totalTurns) {
    cout << BRIGHT_WHITE;
    cout << "  +=========================================================+" << endl;
    cout << "  |  " << BRIGHT_CYAN << "Turn #" << totalTurns
         << BRIGHT_WHITE << "    |   Position: "
         << (pos <= 0 ? BRIGHT_RED : BRIGHT_GREEN) << pos
         << BRIGHT_WHITE << "                              |" << endl;
    cout << "  +---------------------------------------------------------+" << endl;
    cout << "  |  " << BRIGHT_RED   << leftPlayer  << " = LEFT (-) "
         << BRIGHT_WHITE << " | "
         << BRIGHT_GREEN << rightPlayer << " = RIGHT (+)" << BRIGHT_WHITE;
    int pad1 = 25 - (int)leftPlayer.size() - (int)rightPlayer.size();
    for (int i = 0; i < pad1; i++) cout << " ";
    cout << "|" << endl;
    cout << "  +---------------------------------------------------------+" << endl;
    cout << "  |  " << curColor << BOLD << ">> " << curPlayer << "'s turn to roll! <<"
         << RESET << BRIGHT_WHITE;
    int pad2 = 32 - (int)curPlayer.size();
    for (int i = 0; i < pad2; i++) cout << " ";
    cout << "|" << endl;
    cout << "  +=========================================================+" << endl;
    cout << RESET << endl;
}

void showWin(const string& winner, const string& color, int turns) {
    clearScreen();
    cout << endl << endl;
    cout << color << BOLD;
    cout << "  +=====================================================+" << endl;
    cout << "  |                                                     |" << endl;
    cout << "  |   __        _____ _   _ _   _ _____ ____  _        |" << endl;
    cout << "  |   \\ \\      / /_ _| \\ | | \\ | | ____|  _ \\| |       |" << endl;
    cout << "  |    \\ \\ /\\ / / | ||  \\| |  \\| |  _| | |_) | |       |" << endl;
    cout << "  |     \\ V  V /  | || |\\  | |\\  | |___|  _ <| |___    |" << endl;
    cout << "  |      \\_/\\_/  |___|_| \\_|_| \\_|_____|_| \\_\\_____|   |" << endl;
    cout << "  |                                                     |" << endl;
    cout << "  +=====================================================+" << endl;
    cout << RESET << endl;
    cout << "  " << color << BOLD << "  *** " << winner << " wins the game! ***" << RESET << endl << endl;
    cout << "  " << BRIGHT_WHITE << "  Total turns played: " << BRIGHT_YELLOW << turns << RESET << endl << endl;
    cout << "  " << BRIGHT_CYAN << "  Congratulations to the winner!" << RESET << endl << endl;
}

struct GameResult { bool playAgain, goMenu, quit; };

GameResult playGame(const string& p1, const string& p2) {
    int pos = 0;
    int totalTurns = 0;
    string leftPlayer, rightPlayer;

    clearScreen();
    cout << endl;
    cout << BRIGHT_YELLOW << BOLD;
    cout << "  +====================================+" << endl;
    cout << "  |            COIN TOSS               |" << endl;
    cout << "  +====================================+" << endl;
    cout << RESET << endl;
    cout << "  " << BRIGHT_WHITE << "Who calls the coin?" << endl;
    cout << "  " << BRIGHT_RED << "[1] " << p1 << BRIGHT_WHITE << "  or  " << BRIGHT_GREEN << "[2] " << p2 << RESET << endl;
    cout << "  Choice: ";
    int caller;
    while (!(cin >> caller) || (caller != 1 && caller != 2)) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  " << BRIGHT_RED << "Enter 1 or 2: " << RESET;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string callerName = (caller == 1) ? p1 : p2;
    string otherName  = (caller == 1) ? p2 : p1;
    cout << endl << "  " << BRIGHT_CYAN << callerName << ", call it!" << RESET << endl;
    cout << "  " << BRIGHT_WHITE << "[1] HEADS   [2] TAILS: " << RESET;
    int call;
    while (!(cin >> call) || (call != 1 && call != 2)) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  " << BRIGHT_RED << "Enter 1 or 2: " << RESET;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int result = rand() % 2 + 1;
    string resultStr = (result == 1) ? "HEADS" : "TAILS";
    bool callerWon = (call == result);
    string tossWinner = callerWon ? callerName : otherName;
    string tossLoser  = callerWon ? otherName  : callerName;
    cout << endl;
    cout << "  " << BRIGHT_YELLOW << BOLD << "  ==>  " << resultStr << "  <==" << RESET << endl << endl;
    cout << "  " << BRIGHT_GREEN << BOLD << tossWinner << " wins the toss!" << RESET << endl << endl;
    cout << "  " << BRIGHT_WHITE << tossWinner << " goes FIRST and plays the " << BRIGHT_RED << "LEFT (-)" << BRIGHT_WHITE << " side." << RESET << endl;
    cout << "  " << BRIGHT_WHITE << tossLoser  << " plays the " << BRIGHT_GREEN << "RIGHT (+)" << BRIGHT_WHITE << " side." << RESET << endl;
    leftPlayer  = tossWinner;
    rightPlayer = tossLoser;
    pressEnter();

    int curIdx = (p1 == tossWinner) ? 1 : 2;
    bool gameOver = false;
    string winner, winColor;

    while (!gameOver) {
        clearScreen();
        string curName  = (curIdx == 1) ? p1 : p2;
        string curColor = (curName == leftPlayer) ? BRIGHT_RED : BRIGHT_GREEN;
        int    curDir   = (curName == leftPlayer) ? -1 : +1;
        totalTurns++;

        printBoard(pos);
        showStatus(curName, curColor, leftPlayer, rightPlayer, pos, totalTurns);

        cout << "  " << curColor << BOLD << curName << RESET
             << BRIGHT_WHITE << ", press ENTER to roll the dice!" << RESET << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int roll = rand() % 6 + 1;
        cout << endl << "  " << BRIGHT_CYAN << curName << " rolled:" << RESET << endl << endl;
        printDice(roll);
        cout << endl;
        cout << "  " << curColor << BOLD << "==> Rolled: " << roll << " <==" << RESET << endl << endl;

        int prev = pos;
        pos += curDir * roll;
        if (pos <= -7) { pos = -7; gameOver = true; winner = leftPlayer;  winColor = BRIGHT_RED;   }
        if (pos >=  7) { pos =  7; gameOver = true; winner = rightPlayer; winColor = BRIGHT_GREEN; }

        cout << "  " << BRIGHT_WHITE << "Character moved: " << BRIGHT_YELLOW << prev
             << BRIGHT_WHITE << "  -->  " << BRIGHT_YELLOW << pos << RESET << endl << endl;

        if (!gameOver) {
            pressEnter();
            curIdx = (curIdx == 1) ? 2 : 1;
        }
    }

    showWin(winner, winColor, totalTurns);
    printBoard(pos);

    cout << endl;
    cout << BRIGHT_WHITE;
    cout << "  +====================================+" << endl;
    cout << "  |        What would you like?         |" << endl;
    cout << "  +------------------------------------+" << endl;
    cout << "  |  " << BRIGHT_GREEN  << "[1]  Play Again              " << BRIGHT_WHITE << "  |" << endl;
    cout << "  |  " << BRIGHT_CYAN   << "[2]  Main Menu               " << BRIGHT_WHITE << "  |" << endl;
    cout << "  |  " << BRIGHT_RED    << "[3]  Quit                    " << BRIGHT_WHITE << "  |" << endl;
    cout << "  +====================================+" << endl;
    cout << RESET << endl << "  Choice: ";
    int ch;
    while (!(cin >> ch) || ch < 1 || ch > 3) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  " << BRIGHT_RED << "Enter 1, 2, or 3: " << RESET;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    GameResult r = {false, false, false};
    if (ch == 1) r.playAgain = true;
    else if (ch == 2) r.goMenu = true;
    else r.quit = true;
    return r;
}

int main() {
    srand((unsigned)time(nullptr));
    showSplash();
    bool running = true;
    while (running) {
        clearScreen();
        cout << endl;
        cout << BRIGHT_CYAN << BOLD;
        cout << "  +====================================+" << endl;
        cout << "  |       *** THE HOUSE GAME ***        |" << endl;
        cout << "  +====================================+" << endl;
        cout << RESET << endl;
        cout << "  " << BRIGHT_GREEN  << "[1]  Play Game" << RESET << endl;
        cout << "  " << BRIGHT_YELLOW << "[2]  How To Play" << RESET << endl;
        cout << "  " << BRIGHT_RED    << "[3]  Quit" << RESET << endl;
        cout << endl << "  Choice: ";
        int ch;
        while (!(cin >> ch) || ch < 1 || ch > 3) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  " << BRIGHT_RED << "Enter 1, 2, or 3: " << RESET;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (ch == 1) {
            string p1, p2;
            getNames(p1, p2);
            bool keep = true;
            while (keep) {
                GameResult r = playGame(p1, p2);
                if (r.playAgain)  keep = true;
                else if (r.goMenu) keep = false;
                else { keep = false; running = false; }
            }
        } else if (ch == 2) {
            showHowToPlay();
        } else {
            clearScreen();
            cout << endl << endl;
            cout << BRIGHT_CYAN << BOLD;
            cout << "  +====================================+" << endl;
            cout << "  |  Thanks for playing! See you soon!  |" << endl;
            cout << "  +====================================+" << endl;
            cout << RESET << endl;
            running = false;
        }
    }
    return 0;
}
