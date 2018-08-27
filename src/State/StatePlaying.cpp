#include "State/StatePlaying.hpp"
#include "Game.hpp"
#include "State/StatePause.hpp"
#include <string>

StatePlaying::StatePlaying(Game &game)
    : mGame(game), mGameWindow(std::make_unique<Window>(
                       game.getBoardSize().y, game.getBoardSize().x, 1,
                       (COLS - (game.getBoardSize().x / 2)) / 2)),
      mPlayer(2, 2), mApple(std::make_unique<Apple>(game)) {
    mGameWindow->setBox(true);
    mGameWindow->setKeypad(true);
    mGameWindow->clear();
    mGameWindow->setDelay(false);
}

StatePlaying::~StatePlaying() {
    mGame.renderer().clearAll();
    mGame.renderer().refreshAll();
    mGameWindow->clear();
}

void StatePlaying::update() {
    if (canMove())
        mPlayer.move();

    if (mPlayer.getPosition() == mApple->getPosition()) {
        mGame.addScore(1);
        mPlayer.pushPart();
        mApple = std::make_unique<Apple>(mGame);
    }

    mGame.renderer().sleep(150);
}

void StatePlaying::input() {
    int ch;
    ch = mGameWindow->getKey();

    switch (ch) {
    case 'q':
        mGame.pushState(std::make_unique<StatePause>(mGame));
        break;
    case KEY_UP:
        mPlayer.face(Point(-1, 0));
        break;
    case KEY_RIGHT:
        mPlayer.face(Point(0, 1));
        break;
    case KEY_DOWN:
        mPlayer.face(Point(1, 0));
        break;
    case KEY_LEFT:
        mPlayer.face(Point(0, -1));
        break;
    }
}

void StatePlaying::render(Renderer &renderer) {
    mGameWindow->erase();

    mGameWindow->print(mApple->getPosition().y, mApple->getPosition().x,
                       std::string(1, mApple->getChar()), Color::Red);

    // Color the head yellow and rest of the body green.
    for (auto &part : mPlayer.parts()) {
        if (part.getPosition() == mPlayer.parts().begin()->getPosition()) {
            mGameWindow->print(part.getPosition().y, part.getPosition().x,
                               std::string(1, part.getChar()), Color::Yellow);
        } else {
            mGameWindow->print(part.getPosition().y, part.getPosition().x,
                               std::string(1, part.getChar()), Color::Green);
        }
    }

    mGameWindow->refresh();
}

bool StatePlaying::canMove() {
    Point tmp(mPlayer.getPosition() + mPlayer.facing());

    // Magic - 1 because of the border that counts to the window size.
    return (tmp.y > 0 && tmp.y < mGameWindow->size().y - 1 && tmp.x > 0 &&
            tmp.x < mGameWindow->size().x - 1);
}