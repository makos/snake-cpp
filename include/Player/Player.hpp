/*
 * Player.hpp - a Player is made of PlayerParts.
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

    void move();
    Point &getPosition();

    Point &facing();
    void face(const Point &dir);

    std::vector<PlayerPart> &parts();
    void pushPart();
    void insertPart();

  private:
    std::vector<PlayerPart> mParts;
    Point mPosition;
    Point mFacing;
};