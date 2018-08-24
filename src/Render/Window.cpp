#include "Render/Window.hpp"

Window::Window(int height, int width, int posy, int posx)
    : mWindow(std::unique_ptr<WINDOW>(newwin(height, width, posy, posx))) {}

Window::~Window() { delwin(mWindow.get()); }

WINDOW *Window::get() { return mWindow.get(); }

int Window::setBox() { return box(mWindow.get(), 0, 0); }

int Window::refreshWin() { return wrefresh(mWindow.get()); }

int Window::eraseWin() { return werase(mWindow.get()); }

int Window::clearWin() { return wclear(mWindow.get()); }