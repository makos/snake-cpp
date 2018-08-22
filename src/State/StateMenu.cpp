#include "State/StateMenu.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "Render.hpp"
#include "State/StatePlaying.hpp"
#include <curses.h>

StateMenu::StateMenu(Game &game)
    : mGame(std::make_unique<Game>(game)),
      mMenu(std::make_unique<Menu>(Menu())) {
    mMenu->addItem("* New *", newClicked);
    mMenu->addItem("* Exit *", exitClicked);
}

void StateMenu::update() {}

void StateMenu::input() {
    int ch;
    ch = getch();

    switch (ch) {
    case 'Q':
        mGame->setRunning(false);
        break;
    case 'n':
        mGame->setState(std::make_unique<StatePlaying>(StatePlaying(*mGame)));
        break;
    }
}

void StateMenu::render(Render &render) {
    erase();
    int i = 0;
    for (auto const &item : mMenu->items()) {
        mvprintw(i, 1, item.first.c_str());
        i++;
    }
    refresh();
}

void StateMenu::newClicked() {}

void StateMenu::exitClicked() { mGame->setRunning(false); }