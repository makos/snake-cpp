/*
 * main.cpp - ncurses, game structures etc. initialization and hand-off.
 * This should be detached from the actual logic as much as possible.
 */
#include "player.hpp"
#include "point.hpp"
#include "render.hpp"
#include <curses.h>

int main(int argc, char *argv[]) {
    Render init;
    WINDOW *mainWindow = newwin(10, 20, 0, 0);
    box(mainWindow, 0, 0);

    wattron(mainWindow, COLOR_PAIR(Color::Red));
    mvwprintw(mainWindow, 1, 1, "Dupa szatana");
    wattroff(mainWindow, COLOR_PAIR(Color::Red));

    wrefresh(mainWindow);
    wgetch(mainWindow);

    return 0;
}