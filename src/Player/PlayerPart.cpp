#include "Player/PlayerPart.hpp"
#include "Util/Point.hpp"

PlayerPart::PlayerPart(const Point &pos) : mPosition(pos) {}

Point &PlayerPart::getPosition() { return mPosition; }