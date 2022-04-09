#include "Screen.hpp"
#include <ncurses.h>

Screen::Screen() {
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

Screen::~Screen() { clear(); }

void Screen::print(const char *message) { printw(message); }

int Screen::height() { return this->_height; }

int Screen::width() { return this->_width; }
