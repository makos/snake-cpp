#include "Entities/Player.hpp"
#include <iterator>

// Every constructor starts with Player facing down - (1, 0).
Player::Player()
    : mParts(1, PlayerPart(0, 0)), mPosition(0, 0), mFacing(1, 0) {}

Player::Player(int y, int x)
    : mParts(1, PlayerPart(y, x)), mPosition(y, x), mFacing(1, 0) {}

Player::Player(const Point &pos)
    : mParts(1, PlayerPart(pos)), mPosition(pos), mFacing(1, 0) {}

void Player::move() {
    insertPart();
    mParts.pop_back();
}

Point &Player::getPosition() { return mParts[0].getPosition(); }

Point &Player::facing() { return mFacing; }

void Player::face(const Point &dir) { mFacing = dir; }

std::vector<PlayerPart> &Player::parts() { return mParts; }

void Player::pushPart() { mParts.emplace_back(mParts.rbegin()->getPosition()); }

void Player::insertPart() {
    mParts.emplace(mParts.begin(), mParts.begin()->getPosition() + mFacing);
}