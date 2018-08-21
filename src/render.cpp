#include "render.hpp"
// #include "entity.hpp"
#include "point.hpp"
#include <curses.h>

Render::Render() {
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
}

// Stop ncurses to return to default terminal mode.
Render::~Render() { endwin(); }
