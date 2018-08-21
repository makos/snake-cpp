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
    WINDOW *board = game.getWindow("board");

    box(board, 0, 0);

    wattron(board, COLOR_PAIR(Color::Red));
    mvwprintw(board, 1, 1, "board");
    wattroff(board, COLOR_PAIR(Color::Red));

    while (game.isRunning()) {

        game.getInput();
        werase(board);
        mvwprintw(board, 1, 1, "board");
    }

    return 0;
}