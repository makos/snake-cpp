#include "State/StateMenu.hpp"
#include <curses.h>
#include "Game.hpp"
#include "Menu/Menu.hpp"
#include "Renderer/Renderer.hpp"
#include "State/Callback.hpp"
#include "State/StatePlaying.hpp"

// Create two default menu items when the state is instantiated.
StateMenu::StateMenu(Game &game)
    : mGame(game),
      mWindow(
          std::make_unique<Window>(10, 16, (LINES / 2) - 5, (COLS / 2) - 8)),
      mMenu(std::make_unique<Menu>(game)),
      mItemSelected(0) {
    // mMenu->addItem("  New  ", Callback::newClicked);
    // mMenu->addItem("Settings", Callback::settingsClicked);
    // mMenu->addItem("  Exit  ", Callback::exitClicked);
    mWindow->setBox(true);
    mWindow->setKeypad(true);
    mWindow->setDelay(false);
}

StateMenu::~StateMenu() { mWindow->clear(); }

void StateMenu::addItem(const char *text, fpCallback callback) {
    mMenu->addItem(text, callback);
}

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
        // KEY_ENTER in ncurses is actually the numpad Enter. So I had to use
        // '\n' (and '\r' just in case).
        case '\n':
        case '\r':
            mMenu->clickItem(mItemSelected);
            break;
    }
}

void StateMenu::render(Renderer &renderer) {
    mWindow->erase();
    // int i = 1;
    int y = (mWindow->size().y / 2) - (mMenu->items().size() / 2);
    // - 4 because "Settings" (longest item in the menu) is 8 characters long,
    // so half of that.
    int x = (mWindow->size().x / 2) - 4;
    for (auto const &item : mMenu->items()) {
        item->id() == mItemSelected
            ? mWindow->print(y, x, item->text(), A_REVERSE)
            : mWindow->print(y, x, item->text());
        y++;
    }
    mWindow->refresh();
}