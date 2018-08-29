/*
 * Player.hpp - a Player is made of PlayerParts.
 */
#pragma once
// #include "Entities/Entity.hpp"
#include <vector>
#include "Entities/PlayerPart.hpp"
#include "Util/Point.hpp"

class Player {
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