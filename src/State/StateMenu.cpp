#include "State/StateMenu.hpp"
#include "Game.hpp"
#include "Menu/Menu.hpp"
#include "Renderer/Renderer.hpp"
#include "State/Callback.hpp"
#include "State/StatePlaying.hpp"
#include <curses.h>

// New game button.
// void Callback::newClicked(Game &game) {
//     game.pushState(std::make_unique<StatePlaying>(game));
// }

// // Exit button.
// void Callback::exitClicked(Game &game) { game.setRunning(false); }

// Create two default menu items when the state is instantiated.
StateMenu::StateMenu(Game &game)
    : mGame(game),
      mWindow(std::make_unique<Window>(5, 10, LINES / 2, (COLS - 5) / 2)),
      mMenu(std::make_unique<Menu>(game)), mItemSelected(0) {
    mMenu->addItem("* New  *", Callback::newClicked);
    mMenu->addItem("* Exit *", Callback::exitClicked);
    mWindow->setBox(true);
    mWindow->setKeypad(true);
    mWindow->setDelay(false);
}

StateMenu::~StateMenu() { mWindow->clear(); }

// Not really anything to update in a static menu.
void StateMenu::update() {}

void StateMenu::input() {
    int ch;
    ch = mWindow->getKey();

    switch (ch) {
    case 'Q':
        mGame.setRunning(false);
        break;
    case KEY_UP:
        mItemSelected =
            (mItemSelected - 1) % (unsigned int)mMenu->items().size();
        break;
    case KEY_DOWN:
        mItemSelected =
            (mItemSelected + 1) % (unsigned int)mMenu->items().size();
        break;
    // KEY_ENTER in ncurses is actually the numpad Enter. So I had to use '\n'
    // (and '\r' just in case).
    case '\n':
    case '\r':
        mMenu->clickItem(mItemSelected);
        break;
    }
}

void StateMenu::render(Renderer &renderer) {
    mWindow->erase();
    int i = 1;
    // This is really neat syntax, thanks C++ (no sarcasm!).
    for (auto const &item : mMenu->items()) {
        item->id() == mItemSelected
            ? renderer.print(*mWindow, i, 1, item->text(), A_REVERSE)
            : renderer.print(*mWindow, i, 1, item->text());
        i += 2;
    }
    mWindow->refresh();
}