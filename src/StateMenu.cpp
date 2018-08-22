#include "StateMenu.hpp"
#include "Game.hpp"
#include "Render.hpp"
#include "StatePlaying.hpp"
#include <curses.h>

StateMenu::StateMenu(Game &game) : mGame(&game) {}

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
    render.print(1, 1, "MAIN MENU");
    render.print(2, 1, "* New *");
    render.print(3, 1, "* Exit *");
    refresh();
}