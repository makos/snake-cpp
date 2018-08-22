#include "PlayerPart.hpp"
#include "Point.hpp"

PlayerPart::PlayerPart(const Point &pos) : mPosition(pos) {}

Point &PlayerPart::getPosition() { return mPosition; }