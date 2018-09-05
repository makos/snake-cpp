#include "Renderer/Window.hpp"

Window::Window(int height, int width, int posy, int posx)
    : mWindow(std::unique_ptr<WINDOW>(newwin(height, width, posy, posx))),
      mBox(false) {}

WINDOW *Window::get() { return mWindow.get(); }

void Window::print(int y, int x, std::string msg) {
    mvwprintw(mWindow.get(), y, x, msg.c_str());
}

void Window::print(int y, int x, std::string msg, Color color) {
    wattron(mWindow.get(), COLOR_PAIR(color));
    mvwprintw(mWindow.get(), y, x, msg.c_str());
    wattroff(mWindow.get(), COLOR_PAIR(color));
}

void Window::print(int y, int x, std::string msg, chtype attr) {
    wattron(mWindow.get(), attr);
    mvwprintw(mWindow.get(), y, x, msg.c_str());
    wattroff(mWindow.get(), attr);
}

void Window::print(Point pos, std::string msg) {
    mvwprintw(mWindow.get(), pos.y, pos.x, msg.c_str());
}

void Window::print(Point pos, std::string msg, Color color) {
    wattron(mWindow.get(), COLOR_PAIR(color));
    mvwprintw(mWindow.get(), pos.y, pos.x, msg.c_str());
    wattroff(mWindow.get(), COLOR_PAIR(color));
}

void Window::print(Point pos, std::string msg, chtype attr) {
    wattron(mWindow.get(), attr);
    mvwprintw(mWindow.get(), pos.y, pos.x, msg.c_str());
    wattroff(mWindow.get(), attr);
}

void Window::setBox(bool state) { mBox = state; }

int Window::setDelay(bool state) {
    if (state)
        return nodelay(mWindow.get(), FALSE);
    else
        return nodelay(mWindow.get(), TRUE);
}

int Window::setKeypad(bool state) {
    if (state)
        return keypad(mWindow.get(), TRUE);
    else
        return keypad(mWindow.get(), FALSE);
}

int Window::refresh() {
    if (mBox) box(mWindow.get(), 0, 0);
    return wrefresh(mWindow.get());
}

int Window::erase() { return werase(mWindow.get()); }

int Window::clear() { return wclear(mWindow.get()); }

int Window::getKey() { return wgetch(mWindow.get()); }

Point Window::size() {
    return Point(getmaxy(mWindow.get()), getmaxx(mWindow.get()));
}

Point Window::position() {
    return Point(getbegy(mWindow.get()), getbegx(mWindow.get()));
}