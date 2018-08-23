#include "State/StateMenu.hpp"
#include "Game.hpp"
// #include "Menu.hpp"
#include "Render.hpp"
#include "State/StatePlaying.hpp"
#include <curses.h>
#include <iostream>

void Callback::newClicked(Game &game) {}

void Callback::exitClicked(Game &game) {
    game.setRunning(false);
    std::cout << "callback::exitClicked" << std::endl;
}

StateMenu::StateMenu(Game &game)
    : mGame(game), mMenu(std::make_unique<Menu>(game)), mItemSelected(0) {
    mMenu->addItem("* New *", Callback::newClicked);
    mMenu->addItem("* Exit *", Callback::exitClicked);
}

// StateMenu::~StateMenu() {}

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
    case 'e':
        mMenu->clickItem("* Exit *");
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