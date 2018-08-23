#include "State/StatePlaying.hpp"
#include "Game.hpp"
#include "Util/Render.hpp"

StatePlaying::StatePlaying(Game &game) : mGame(&game) {}

void StatePlaying::update() {}

void StatePlaying::input() {
    int ch;
    ch = getch();

    switch (ch) {
    case 'Q':
        mGame->setRunning(false);
        break;
    }
}

void StatePlaying::render(Render &render) {
    erase();
    render.print(5, 5, "Game wooo", Color::Yellow);
    refresh();
}