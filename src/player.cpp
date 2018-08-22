#include "Player.hpp"

// Class PlayerPart
PlayerPart::PlayerPart(const Point &pos) : mPosition(pos) {}

Point &PlayerPart::getPosition() { return mPosition; }

// Class player
Player::Player() : mPosition(0, 0), mFacing(0, -1), mChar('#') {}

Player::Player(int y, int x) : mPosition(y, x), mFacing(0, -1), mChar('#') {}

Player::Player(const Point &pos) : mPosition(pos), mFacing(0, -1), mChar('#') {}

// TODO:
void Player::move(const Point &dir) {}

Point &Player::getPosition() { return mPosition; }

char Player::getChar() { return mChar; }

void Player::setChar(char ch) { mChar = ch; }

Point &Player::facing() { return mFacing; }