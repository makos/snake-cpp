/*
 * PlayerPart.hpp - PlayerParts are objects that the Player is made of.
 * Basically squares that have a position and are put in concrete order inside a
 * vector in the Player class.
 */
#pragma once
#include "Util/Point.hpp"

class PlayerPart {
   public:
    PlayerPart(const Point &pos);
    PlayerPart(int y, int x);

    Point &getPosition();

    char getChar();

   private:
    Point mPosition;
    char mChar;
};
