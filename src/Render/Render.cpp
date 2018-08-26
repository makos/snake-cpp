#include "Render/Render.hpp"
#include "Util/Point.hpp"

Render::Render() {
    // Initialize ncurses and set default behavior.
    initscr();
    cbreak();
    noecho();
    start_color();
    curs_set(0);

    // Initialize color pairs
    init_pair(Color::Black, COLOR_BLACK, COLOR_BLACK);
    init_pair(Color::Red, COLOR_RED, COLOR_BLACK);
    init_pair(Color::Green, COLOR_GREEN, COLOR_BLACK);
    init_pair(Color::Yellow, COLOR_YELLOW, COLOR_BLACK);
    init_pair(Color::Blue, COLOR_BLUE, COLOR_BLACK);
    init_pair(Color::Magenta, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(Color::Cyan, COLOR_CYAN, COLOR_BLACK);
    init_pair(Color::White, COLOR_WHITE, COLOR_BLACK);
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

void Render::print(int y, int x, std::string msg, chtype attr) {
    attron(attr);
    mvprintw(y, x, msg.c_str());
    attroff(attr);
}

void Render::print(WINDOW *win, int y, int x, std::string msg, chtype attr) {
    wattron(win, attr);
    mvwprintw(win, y, x, msg.c_str());
    wattroff(win, attr);
}

void Render::sleep(int ms) { napms(ms); }