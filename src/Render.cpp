/* render.cpp - "renderer" functionality wrapper for ncurses.
 *
 * It operates on a stack of windows, all methods like print(), update(),
 * clear() work only on the topmost window. Use pushWindow() and popWindow() to
 * add and remove windows for menus etc.
 *
 */
#include "Render.hpp"
#include "Point.hpp"

Render::Render(int height, int width) : mGameboard(nullptr), drawBox(false) {
    // Initialize ncurses and set default behavior.
    initscr();
    cbreak();
    noecho();
    start_color();
    curs_set(0);

    // Initialize color pairs
    init_pair(Color::Red, COLOR_RED, COLOR_BLACK);
    init_pair(Color::Green, COLOR_GREEN, COLOR_BLACK);
    init_pair(Color::Yellow, COLOR_YELLOW, COLOR_BLACK);

    mGameboard = newwin(height, width, 0, 0);
}

int Render::kpad(bool state) { return keypad(stdscr, state); }

int Render::kpad(WINDOW *win, bool state) { return keypad(win, state); }

void Render::setBox(bool state) {
    drawBox = state;
    if (drawBox)
        box(mGameboard, 0, 0);
}

// Stop ncurses to return to default terminal mode.
Render::~Render() { endwin(); }

void Render::print(WINDOW *win, int y, int x, std::string msg) {
    mvwprintw(win, y, x, msg.c_str());
}

void Render::print(WINDOW *win, int y, int x, std::string msg, Color color) {
    wattron(win, COLOR_PAIR(color));
    mvwprintw(win, y, x, msg.c_str());
    wattron(win, COLOR_PAIR(color));
}

void Render::print(int y, int x, std::string msg) {
    mvprintw(y, x, msg.c_str());
}

void Render::print(int y, int x, std::string msg, Color color) {
    attron(COLOR_PAIR(color));
    mvprintw(y, x, msg.c_str());
    attroff(COLOR_PAIR(color));
}

void Render::update() {
    werase(mGameboard);
    if (drawBox)
        box(mGameboard, 0, 0);
    wrefresh(mGameboard);
}

void Render::clear() { wclear(mGameboard); }

int Render::getKey() { return wgetch(mGameboard); }
