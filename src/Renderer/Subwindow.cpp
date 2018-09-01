#include "Renderer/Subwindow.hpp"
#include "Renderer/Window.hpp"

Subwindow::Subwindow(IWindow *win, int height, int width, int posy, int posx)
    : mWindow(subwin(win->get(), height, width, posy, posx)), mBox(false) {}

void Subwindow::print(int y, int x, std::string msg) {
    mvwprintw(mWindow.get(), y, x, msg.c_str());
}

void Subwindow::print(int y, int x, std::string msg, Color color) {
    wattron(mWindow.get(), COLOR_PAIR(color));
    mvwprintw(mWindow.get(), y, x, msg.c_str());
    wattroff(mWindow.get(), COLOR_PAIR(color));
}

void Subwindow::print(int y, int x, std::string msg, chtype attr) {
    wattron(mWindow.get(), attr);
    mvwprintw(mWindow.get(), y, x, msg.c_str());
    wattroff(mWindow.get(), attr);
}

void Subwindow::print(Point pos, std::string msg) {
    mvwprintw(mWindow.get(), pos.y, pos.x, msg.c_str());
}

void Subwindow::print(Point pos, std::string msg, Color color) {
    wattron(mWindow.get(), COLOR_PAIR(color));
    mvwprintw(mWindow.get(), pos.y, pos.x, msg.c_str());
    wattroff(mWindow.get(), COLOR_PAIR(color));
}

void Subwindow::print(Point pos, std::string msg, chtype attr) {
    wattron(mWindow.get(), attr);
    mvwprintw(mWindow.get(), pos.y, pos.x, msg.c_str());
    wattroff(mWindow.get(), attr);
}

void Subwindow::setBox(bool state) { mBox = state; }

int Subwindow::setDelay(bool state) {
    if (state)
        return nodelay(mWindow.get(), FALSE);
    else
        return nodelay(mWindow.get(), TRUE);
}

int Subwindow::setKeypad(bool state) {
    if (state)
        return keypad(mWindow.get(), TRUE);
    else
        return keypad(mWindow.get(), FALSE);
}

int Subwindow::refresh() {
    if (mBox) {
        box(mWindow.get(), 0, 0);
    }
    return wrefresh(mWindow.get());
}

int Subwindow::erase() { return werase(mWindow.get()); }

int Subwindow::clear() { return wclear(mWindow.get()); }

int Subwindow::getKey() { return wgetch(mWindow.get()); }

Point Subwindow::size() {
    return Point(getmaxy(mWindow.get()), getmaxx(mWindow.get()));
}

WINDOW *Subwindow::get() { return mWindow.get(); }