#pragma once

#include "entity.hpp"

class Player : public IEntity {
  public:
    Player();
    Player(int y, int x);
    Player(const Point &pos);

    void draw(const Point &pos);
    void move(const Point &dir);
    Point &getPosition();
    char getChar();
    void setChar(char ch);

  private:
    Point *mPosition;
    char mChar;
};