#include <ncurses.h>

// Main character initial position and symbol
int row = 10, col = 10;
const char main_char = '@';

// Initialize ncurses
void initScreen() {
    // init ncurses data structures and allocate memory
    initscr();

    /**
     * Clear the internal state of the screen.
     * Does not clear the visual screen until refresh is called.
     */
    clear();

    // prevents user input from being echoed
    noecho();

    // disable line buffering
    cbreak();

    // enable the keypad of the user's terminal
    keypad(stdscr, TRUE);

    // make the cursor invisible
    curs_set(0);
}

void welcomeMessage() {
    printw("Welcome to Rogue.\nPress any key to start.\nIf you want to quit, press \"Q\" or \"q\"");
}

int main() {
    initScreen();
    welcomeMessage();
    
    // wait until the user presses a key
    int ch = getch();

    clear();

    // main game loop
    while(1) {
        // quit game if user presses Q
        if (ch == 'q' || ch == 'Q') {
            endwin();
            break;
        } else {
            mvaddch(row, col, main_char);
            ch = getch();
        }
    }
}