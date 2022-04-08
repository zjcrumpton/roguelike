#include <ncurses.h>
#include "Screen.hpp"
#include "Constants.hpp"

struct Position {
    int x;
    int y;
};

struct Player {
    Position pos;
    char symbol;
};

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

void game_loop(Screen& screen, Player& player, char input) {

    while(1) {
        // quit game if user presses Q
        if (input == 'q' || input == 'Q') {
            endwin();
            break;
        } else {
            mvaddch(player.pos.y, player.pos.x, player.symbol);
            input = getch();
            process_input(input, player);
            screen.~Screen();
        }
    }
}

int main() {
    Screen screen;
    screen.print(GameText::welcome);
    
    // wait until the user presses a key
    int ch = getch();
    clear();

    Player player;
    player.pos.x = 10;
    player.pos.y = 10;
    player.symbol = '@';
    game_loop(screen, player, ch);
}