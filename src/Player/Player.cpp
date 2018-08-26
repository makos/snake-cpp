#include "Player/Player.hpp"

// Class player
Player::Player() : mParts(), mPosition(0, 0), mFacing(1, 0), mChar('#') {}

Player::Player(int y, int x)
    : mParts(), mPosition(y, x), mFacing(1, 0), mChar('#') {}

Player::Player(const Point &pos)
    : mParts(), mPosition(pos), mFacing(1, 0), mChar('#') {}

void Player::move(const Point &dir) { mPosition += dir; }

Point &Player::getPosition() { return mPosition; }

char Player::getChar() { return mChar; }

void Player::setChar(char ch) { mChar = ch; }

Point &Player::facing() { return mFacing; }

void Player::face(const Point &dir) { mFacing = dir; }