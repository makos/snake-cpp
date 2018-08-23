/*
 * PlayerPart.hpp - PlayerParts are objects that the Player is made of.
 * Basically squares that have a position and are put in concrete order inside a
 * vector in the Player class.
 */
#pragma once
#include "Point.hpp"

class PlayerPart {
  public:
    PlayerPart(const Point &pos);

    Point &getPosition();

  private:
    Point mPosition;
};
