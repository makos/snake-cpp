#include "Render/Window.hpp"

Window::Window(int height, int width, int posy, int posx)
    : mWindow(std::unique_ptr<WINDOW>(newwin(height, width, posy, posx))) {}

// Window::~Window() { delwin(mWindow.get()); }

WINDOW *Window::get() { return mWindow.get(); }

int Window::setBox() { return box(mWindow.get(), 0, 0); }

int Window::refresh() { return wrefresh(mWindow.get()); }

int Window::erase() { return werase(mWindow.get()); }

int Window::clear() { return wclear(mWindow.get()); }

int Window::getKey() { return wgetch(mWindow.get()); }