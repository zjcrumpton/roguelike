#ifndef SCREEN_H
#define SCREEN_H

class Screen {
  int _height = 100, _width = 100;

public:
  // Initialize NCurses
  Screen();
  // Clear NCurses
  ~Screen();
  // Print a message to the screen
  void print(const char *message);
  // Getters
  int height();
  int width();
};

#endif
