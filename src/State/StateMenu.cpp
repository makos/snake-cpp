#include "State/StateMenu.hpp"
#include "Game.hpp"
#include "Render.hpp"
#include "State/StatePlaying.hpp"
#include <curses.h>
#include <iostream>

void Callback::newClicked(Game &game) {}

void Callback::exitClicked(Game &game) { game.setRunning(false); }

StateMenu::StateMenu(Game &game)
    : mGame(game), mMenu(std::make_unique<Menu>(game)), mItemSelected(0) {
    mMenu->addItem("* New *", Callback::newClicked);
    mMenu->addItem("* Exit *", Callback::exitClicked);
}

void StateMenu::update() {}

void StateMenu::input() {
    int ch;
    ch = getch();

    switch (ch) {
    case 'Q':
        mGame.setRunning(false);
        break;
    case 'n':
        mGame.setState(std::make_unique<StatePlaying>(mGame));
        break;
    case KEY_UP:
        mItemSelected =
            (mItemSelected - 1) % (unsigned int)mMenu->items().size();
        break;
    case KEY_DOWN:
        mItemSelected =
            (mItemSelected + 1) % (unsigned int)mMenu->items().size();
        break;
    case '\n':
    case '\r':
        mMenu->clickItem(mItemSelected);
        break;
    }
}

void StateMenu::render(Render &render) {
    erase();
    int i = 0;
    for (auto const &item : mMenu->items()) {
        if (item->id() == mItemSelected)
            attron(A_REVERSE);
        mvprintw(i, 1, item->text().c_str());
        attroff(A_REVERSE);
        i++;
    }
    refresh();
}