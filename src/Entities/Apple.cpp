#include "Entities/Apple.hpp"
#include "Game.hpp"
#include <random>

Apple::Apple(Game &game) : mGame(game), mPosition(), mChar('@') {
    std::uniform_int_distribution<int> uniY(1, game.getBoardSize().y - 1);
    std::uniform_int_distribution<int> uniX(1, game.getBoardSize().x - 1);

    mPosition = Point(uniY(mGame.rng()), uniX(mGame.rng()));
}

Point Apple::getPosition() { return mPosition; }

char Apple::getChar() { return mChar; }
