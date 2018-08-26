/*
 * Player.hpp - player class.
 */
#pragma once
#include "Entity.hpp"
#include "Player/PlayerPart.hpp"
#include "Util/Point.hpp"
#include <vector>

class Player : public IEntity {
  public:
    Player();
    Player(int y, int x);
    Player(const Point &pos);

    void move(const Point &dir);
    Point &getPosition();

    char getChar();
    void setChar(char ch);

    Point &facing();
    void face(const Point &dir);

  private:
    std::vector<PlayerPart> mParts;
    Point mPosition;
    Point mFacing;
    char mChar;
};