#include "State/StatePlaying.hpp"
#include <string>
#include "Game.hpp"
#include "State/Callback.hpp"
#include "State/StateMenu.hpp"

StatePlaying::StatePlaying(Game &game)
    : mGame(game),
      mWindow(std::make_unique<Window>(
          game.getBoardSize().y, game.getBoardSize().x, 1,
          ((COLS / 2) - (game.getBoardSize().x / 2)))),
      mScoreWindow(
          std::make_unique<Window>(1, game.getBoardSize().x, 0,
                                   ((COLS / 2) - (game.getBoardSize().x / 2)))),
      mPlayer(Point::randomPoint(mGame.rng(), 3, game.getBoardSize().y - 4, 3,
                                 game.getBoardSize().x - 4)),
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

    mGame.renderer().sleep(mGame.getSpeed());
}

void StatePlaying::input() {
    int ch;
    ch = mWindow->getKey();

    switch (ch) {
        case 'q': {
            auto pauseMenu = std::make_unique<StateMenu>(mGame);
            pauseMenu->addItem("Continue", Callback::continueClicked);
            pauseMenu->addItem("New", Callback::newClicked);
            pauseMenu->addItem("Settings", Callback::settingsClicked);
            pauseMenu->addItem("Exit", Callback::exitClicked);

            mGame.pushState(std::move(pauseMenu));
        }; break;
        case KEY_UP:
            if (mPlayer.facing() != DIR_DOWN) mPlayer.face(DIR_UP);
            break;
        case KEY_RIGHT:
            if (mPlayer.facing() != DIR_LEFT) mPlayer.face(DIR_RIGHT);
            break;
        case KEY_DOWN:
            if (mPlayer.facing() != DIR_UP) mPlayer.face(DIR_DOWN);
            break;
        case KEY_LEFT:
            if (mPlayer.facing() != DIR_RIGHT) mPlayer.face(DIR_LEFT);
            break;
    }
}

void StatePlaying::render(Renderer &renderer) {
    mWindow->erase();
    mScoreWindow->erase();

    mScoreWindow->print(0, 1, "Score: " + std::to_string(mGame.getScore()));

    mWindow->print(mApple->getPosition(), std::string(1, mApple->getChar()),
                   Color::Red);

    // DEBUG
    // mWindow->print(1, 1, std::to_string(mApple->getPosition().y));
    // mWindow->print(1, 3, std::to_string(mApple->getPosition().x));

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