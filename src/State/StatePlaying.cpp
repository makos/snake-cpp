#include "State/StatePlaying.hpp"
#include "Game.hpp"
#include "Player/Player.hpp"
// #include "Renderer/Renderer.hpp"
#include "State/StatePause.hpp"
// #include "State/StateMenu.hpp"

StatePlaying::StatePlaying(Game &game)
    : mGame(game),
      mGameWindow(std::make_unique<Window>(16, 16, 0, (COLS - 8) / 2)) {
    mGameWindow->setBox(true);
    mGameWindow->setKeypad(true);
    mGameWindow->clear();
    mGameWindow->setDelay(false);
    Player player;
}

void StatePlaying::update() { mGame.renderer().sleep(150); }

void StatePlaying::input() {
    int ch;
    ch = getch();

    switch (ch) {
    case 'q':
        // mGame->popState();
        mGame.pushState(std::make_unique<StatePause>(mGame));
        break;
    }
}

void StatePlaying::render(Renderer &renderer) {
    mGameWindow->erase();

    mGameWindow->refresh();
}