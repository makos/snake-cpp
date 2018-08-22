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
    int ch = '';

    Render render;
    while (ch != 'q') {
        render.print(3, 3, "Dupa szatana");
        render.print(4, 3, "Tęcza szatana", Color::Green);
        ch = render.getInput();
    }

    return 0;
}