#include "State/StateMenu.hpp"
#include "Game.hpp"
#include "Menu/Menu.hpp"
#include "Render.hpp"
#include "State/StatePlaying.hpp"
#include <curses.h>

// New game button.
void Callback::newClicked(Game &game) {
    game.setState(std::make_unique<StatePlaying>(game));
}

// Exit button.
void Callback::exitClicked(Game &game) { game.setRunning(false); }

// Create two default menu items when the state is instantiated.
StateMenu::StateMenu(Game &game)
    : mGame(game), mMenu(std::make_unique<Menu>(game)), mItemSelected(0) {
    mMenu->addItem("* New *", Callback::newClicked);
    mMenu->addItem("* Exit *", Callback::exitClicked);
}

// Not really anything to update in a static menu.
void StateMenu::update() {}

void StateMenu::input() {
    int ch;
    ch = getch();

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

void StateMenu::render(Render &render) {
    erase();
    int i = 0;
    // This is really neat syntax, thanks C++ (no sarcasm!).
    for (auto const &item : mMenu->items()) {
        if (item->id() == mItemSelected)
            attron(A_REVERSE);
        mvprintw(i, 1, item->text().c_str());
        attroff(A_REVERSE);
        i++;
    }
    refresh();
}