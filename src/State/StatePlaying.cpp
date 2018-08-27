#include "State/StatePlaying.hpp"
#include <string>
#include "Game.hpp"
#include "State/StatePause.hpp"

StatePlaying::StatePlaying(Game &game)
    : mGame(game),
      mWindow(std::make_unique<Window>(
          game.getBoardSize().y, game.getBoardSize().x, 1,
          (COLS - (game.getBoardSize().x / 2)) / 2)),
      mScoreWindow(
          std::make_unique<Window>(1, game.getBoardSize().x, 0,
                                   (COLS - (game.getBoardSize().x / 2)) / 2)),
      mPlayer(2, 2),
      mApple(std::make_unique<Apple>(game)) {
    mWindow->setBox(true);
    mWindow->setKeypad(true);
    mWindow->clear();
    mWindow->setDelay(false);
}

StatePlaying::~StatePlaying() {
    mGame.renderer().clearAll();
    mGame.renderer().refreshAll();
    mWindow->clear();
}

void StatePlaying::update() {
    if (canMove()) mPlayer.move();

    if (mPlayer.getPosition() == mApple->getPosition()) {
        mGame.addScore(1);
        mPlayer.pushPart();
        mApple = std::make_unique<Apple>(mGame);
    }

    mGame.renderer().sleep(150);
}

void StatePlaying::input() {
    int ch;
    ch = mWindow->getKey();

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
    mWindow->erase();
    mScoreWindow->erase();

    mScoreWindow->print(0, 1, "Score: " + std::to_string(mGame.getScore()));

    mWindow->print(mApple->getPosition(), std::string(1, mApple->getChar()),
                   Color::Red);

    // Color the head yellow and rest of the body green.
    for (auto &part : mPlayer.parts()) {
        if (part.getPosition() == mPlayer.parts().begin()->getPosition()) {
            mWindow->print(part.getPosition(), std::string(1, part.getChar()),
                           Color::Yellow);
        } else {
            mWindow->print(part.getPosition(), std::string(1, part.getChar()),
                           Color::Green);
        }
    }

    mScoreWindow->refresh();
    mWindow->refresh();
}

bool StatePlaying::canMove() {
    Point tmp(mPlayer.getPosition() + mPlayer.facing());

    // Magic - 1 because of the border that counts to the window size.
    return (tmp.y > 0 && tmp.y < mWindow->size().y - 1 && tmp.x > 0 &&
            tmp.x < mWindow->size().x - 1);
}