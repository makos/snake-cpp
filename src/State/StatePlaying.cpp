#include "State/StatePlaying.hpp"
#include "Game.hpp"
#include "State/StatePause.hpp"
#include <string>

StatePlaying::StatePlaying(Game &game)
    : mGame(game),
      mGameWindow(std::make_unique<Window>(16, 16, 0, (COLS - 8) / 2)),
      mPlayer(2, 2) {
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
    mPlayer.move(mPlayer.facing());
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
    renderer.print(*mGameWindow, mPlayer.getPosition().y,
                   mPlayer.getPosition().x, std::string(1, mPlayer.getChar()));
    mGameWindow->refresh();
}