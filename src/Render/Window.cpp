#include "Window.hpp"

Window::Window(int height, int width, int posy, int posx)
    : mWindow(newwin(height, width, posy, posx)) {}

Window::~Window() { delwin(mWindow); }

WINDOW *Window::get() { return mWindow; }