#include "Renderer/Renderer.hpp"
#include "Renderer/Window.hpp"

Renderer::Renderer() {
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
Renderer::~Renderer() { endwin(); }

void Renderer::print(int y, int x, std::string msg) {
    mvprintw(y, x, msg.c_str());
}

void Renderer::print(int y, int x, std::string msg, Color color) {
    attron(COLOR_PAIR(color));
    mvprintw(y, x, msg.c_str());
    attroff(COLOR_PAIR(color));
}

void Renderer::print(int y, int x, std::string msg, chtype attr) {
    attron(attr);
    mvprintw(y, x, msg.c_str());
    attroff(attr);
}

void Renderer::print(Point pos, std::string msg) {
    mvprintw(pos.y, pos.x, msg.c_str());
}

void Renderer::print(Point pos, std::string msg, Color color) {
    attron(COLOR_PAIR(color));
    mvprintw(pos.y, pos.x, msg.c_str());
    attroff(COLOR_PAIR(color));
}

void Renderer::print(Point pos, std::string msg, chtype attr) {
    attron(attr);
    mvprintw(pos.y, pos.x, msg.c_str());
    attroff(attr);
}

void Renderer::sleep(int ms) { napms(ms); }

void Renderer::clearAll() { clear(); }

void Renderer::eraseAll() { erase(); }

void Renderer::refreshAll() { refresh(); }

void Renderer::setDelay(bool state) {
    if (state)
        nodelay(stdscr, FALSE);
    else
        nodelay(stdscr, TRUE);
}