#include "Character.hpp"

Character::Character(char symbol, int startX, int startY) {
  this->_symbol = symbol;
  this->_x = startX;
  this->_y = startY;
};

void Character::setPos(int x, int y) {
  this->_x = x;
  this->_y = y;
};

int Character::x() { return this->_x; };

int Character::y() { return this->_y; };
