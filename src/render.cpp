/* render.cpp - "renderer" functionality wrapper for ncurses.
 *
 * It operates on a stack of windows, all methods like print(), update(),
 * clear() work only on the topmost window. Use pushWindow() and popWindow() to
 * add and remove windows for menus etc.
 *
 */
#include "render.hpp"
// #include "entity.hpp"
#include "point.hpp"
// #include <curses.h>

Render::Render(int height, int width) : mGameboard(nullptr) {
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
    // mTopWindow = stdscr;
    // mWinStack.push(stdscr);
}

int Render::kpad(bool state) { return keypad(mGameboard, state); }

// Stop ncurses to return to default terminal mode.
Render::~Render() { endwin(); }

void Render::print(int y, int x, std::string msg) {
    // mvwprintw(topWindow(), y, x, msg.c_str());
    mvwprintw(mGameboard, y, x, msg.c_str());
}

void Render::print(int y, int x, std::string msg, Color color) {
    // wattron(topWindow(), COLOR_PAIR(color));
    // mvwprintw(topWindow(), y, x, msg.c_str());
    // wattroff(topWindow(), COLOR_PAIR(color));
    wattron(mGameboard, COLOR_PAIR(color));
    mvwprintw(mGameboard, y, x, msg.c_str());
    wattroff(mGameboard, COLOR_PAIR(color));
}

// void Render::pushWindow(int height, int width, int posy, int posx) {
//     WINDOW *temp = newwin(height, width, posy, posx);
//     mWinStack.push(temp);
// }

// // Popping an element on an empty stack is undefined behavior.
// // We want stdscr to be always at the bottom anyways.
// void Render::popWindow() {
//     if (mWinStack.size() > (std::size_t)1)
//         mWinStack.pop();
// }

void Render::update() {
    werase(mGameboard);
    wrefresh(mGameboard);
}

void Render::clear() { wclear(mGameboard); }

// WINDOW *Render::topWindow() { return mWinStack.top(); }

int Render::getKey() { return wgetch(mGameboard); }
