#include "Constants.hpp"
#include "Screen.hpp"
#include <ncurses.h>

struct Position {
  int x;
  int y;
};

struct Player {
  Position pos;
  char symbol;
};

void process_input(char ch, Player &player, Screen &screen) {
  if (ch == 'a') {
    move(player.pos.y, 0);
    clrtoeol();
    player.pos.x--;
    move(player.pos.y, player.pos.x);
  } else if (ch == 'd') {
    move(player.pos.y, 0);
    clrtoeol();
    player.pos.x++;

  } else if (ch == 'w') {
    move(player.pos.y, 0);
    clrtoeol();
    player.pos.y--;

  } else if (ch == 's') {
    move(player.pos.y, 0);
    clrtoeol();
    player.pos.y++;
  }
}

void game_loop(Screen &screen, Player &player, char input) {

  while (1) {
    // quit game if user presses Q
    if (input == 'q' || input == 'Q') {
      endwin();
      break;
    } else {
      mvaddch(player.pos.y, player.pos.x, player.symbol);
      input = getch();
      process_input(input, player, screen);
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