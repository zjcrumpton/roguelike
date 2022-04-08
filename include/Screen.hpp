#ifndef SCREEN_H
#define SCREEN_H

class Screen {
    int _height, _width;
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
