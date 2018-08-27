#include "Player/PlayerPart.hpp"
#include "Util/Point.hpp"

PlayerPart::PlayerPart(const Point &pos) : mPosition(pos), mChar('#') {}

PlayerPart::PlayerPart(int y, int x) : mPosition(y, x), mChar('#') {}

Point &PlayerPart::getPosition() { return mPosition; }

char PlayerPart::getChar() { return mChar; }