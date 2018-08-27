#include "Entities/Apple.hpp"
#include "Game.hpp"
#include <random>

Apple::Apple(Game &game) : mGame(game), mPosition(), mChar('@') {
    std::uniform_int_distribution<int> uniY(0, game.getBoardSize().y);
    std::uniform_int_distribution<int> uniX(0, game.getBoardSize().x);

    mPosition = Point(uniY(mGame.rng()), uniX(mGame.rng()));
}

Point Apple::getPosition() { return mPosition; }

char Apple::getChar() { return mChar; }
