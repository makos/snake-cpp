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
    Render render;
    Game game;

    box(game.getTopWindow(), 0, 0);

    wattron(game.getTopWindow(), COLOR_PAIR(Color::Red));
    mvwprintw(game.getTopWindow(), 1, 1, "%p", game.getTopWindow());
    wattroff(game.getTopWindow(), COLOR_PAIR(Color::Red));

    game.refreshTopWindow();

    while (game.isRunning()) {

        game.getInput();
        werase(game.getTopWindow());
        mvwprintw(game.getTopWindow(), 1, 1, "%p", game.getTopWindow());
        game.refreshTopWindow();
    }

    return 0;
}