#include "StateMenu.hpp"
#include "Game.hpp"
#include "Render.hpp"
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
    }
}

void StateMenu::render(Render &render) {}