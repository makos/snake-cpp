#include "player.hpp"
#include "point.hpp"

Player::Player() {
    mPosition = new Point(0, 0);
    mChar = '#';
}

Player::Player(int y, int x) : mPosition(new Point(y, x)) { mChar = '#'; }

Player::Player(const Point &pos) : mPosition(new Point(pos)) { mChar = '#'; }

void Player::draw(const Point &pos) {
    // std::cout << "player::draw pos(y,x)=" << pos.y << " " << pos.x <<
    // std::endl;
}

void Player::move(const Point &dir) {
    // std::cout << "player::move dir(y,x)=" << dir.y << " " << dir.x <<
    // std::endl;
}

Point &Player::getPosition() { return *mPosition; }

char Player::getChar() { return mChar; }

void Player::setChar(char ch) { mChar = ch; }