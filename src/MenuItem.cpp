#include "MenuItem.hpp"

MenuItem::MenuItem(const char text[], fpCallback cb)
    : mText(std::string(text)), mCallback(cb) {}

void MenuItem::click() { mCallback(); }