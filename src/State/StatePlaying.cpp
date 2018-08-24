#include "State/StatePlaying.hpp"
#include "Game.hpp"
#include "Render/Render.hpp"
#include "State/StateMenu.hpp"

StatePlaying::StatePlaying(Game &game) : mGame(&game) {}

void StatePlaying::update() {}

void StatePlaying::input() {
    int ch;
    ch = getch();

    switch (ch) {
    case 'q':
        // mGame->setState(std::make_unique<StateMenu>(*mGame));
        // mGame->pushState(std::make_unique<StateMenu>(*mGame));
        mGame->popState();
        break;
    }
}

void StatePlaying::render(Render &render) {
    erase();
    render.print(5, 5, "Game wooo", Color::Yellow);
    refresh();
}