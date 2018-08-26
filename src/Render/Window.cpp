#include "Render/Window.hpp"

Window::Window(int height, int width, int posy, int posx)
    : mWindow(std::unique_ptr<WINDOW>(newwin(height, width, posy, posx))),
      mBox(false) {}

// Window::~Window() { delwin(mWindow.get()); }

WINDOW *Window::get() { return mWindow.get(); }

void Window::setBox(bool state) { mBox = state; }

int Window::setKeypad(bool state) {
    if (state)
        return keypad(mWindow.get(), TRUE);
    else
        return keypad(mWindow.get(), FALSE);
}

int Window::refresh() {
    if (mBox)
        box(mWindow.get(), 0, 0);
    return wrefresh(mWindow.get());
}

int Window::erase() { return werase(mWindow.get()); }

int Window::clear() { return wclear(mWindow.get()); }

int Window::getKey() { return wgetch(mWindow.get()); }