/*
 * main.cpp - ncurses, game structures etc. initialization and hand-off.
 * This should be detached from the actual logic as much as possible.
 */
#include "game.hpp"
#include "player.hpp"
#include "point.hpp"
#include "render.hpp"
#include <curses.h>

int main(int argc, char *argv[]) {
    Render render(10, 20);
    render.kpad(true);
    render.setBox(true);
    int ch = ' ';
    int i = 0;

    while (ch != 'q') {
        render.print(3, 3, std::string("Loop count: ") + std::to_string(i));
        render.print(4, 3, "Tęcza szatana", Color::Green);
        ch = render.getKey();
        render.update();
        i++;
    }

    return 0;
}