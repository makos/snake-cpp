#include "Entities/Apple.hpp"
#include "Game.hpp"

Apple::Apple(Game &game) : mGame(game), mPosition(), mChar('@') {
    mPosition = Point::randomPoint(mGame.rng(), 1, game.getBoardSize().y - 2, 1,
                                   game.getBoardSize().x - 2);
}

Point Apple::getPosition() { return mPosition; }

char Apple::getChar() { return mChar; }
