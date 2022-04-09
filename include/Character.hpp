#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
  int _x, _y;
  char _symbol;

public:
  Character(char symbol, int startX, int startY);

  // Update the character's position
  void setPos(int x, int y);

  // Getters
  int x();
  int y();
};

#endif
