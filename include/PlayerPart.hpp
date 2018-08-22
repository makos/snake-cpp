#pragma once
#include "Point.hpp"

class PlayerPart {
  public:
    PlayerPart(const Point &pos);

    Point &getPosition();

  private:
    Point mPosition;
};
