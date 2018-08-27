#pragma once
#include "Util/Point.hpp"
class Game;

class Apple {
  public:
    Apple(Game &game);

    Point getPosition();
    char getChar();

  private:
    Game &mGame;
    Point mPosition;
    char mChar;
};