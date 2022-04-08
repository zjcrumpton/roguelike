#include <ncurses.h>

struct Position {
    int x;
    int y;
};

struct Player {
    Position pos;
    char symbol;
};

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

void process_input(char ch, Player& player) {
    if (ch == 'a') {
        player.pos.x--;
    } else if (ch == 'd') {
        player.pos.x++;
    } else if (ch == 'w') {
        player.pos.y--;
    } else if (ch == 's') {
        player.pos.y++;
    }
}

void game_loop(Player& player, char input) {

    while(1) {
        // quit game if user presses Q
        if (input == 'q' || input == 'Q') {
            endwin();
            break;
        } else {
            mvaddch(player.pos.y, player.pos.x, player.symbol);
            input = getch();
            process_input(input, player);
        }
    }
}

int main() {
    initScreen();
    welcomeMessage();
    
    // wait until the user presses a key
    int ch = getch();
    clear();

    Player player;
    player.pos.x = 10;
    player.pos.y = 10;
    player.symbol = '@';
    game_loop(player, ch);
}