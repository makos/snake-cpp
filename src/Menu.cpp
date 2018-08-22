#include "Menu.hpp"

void newClickEvent() {}

Menu::Menu() : mItems() {}

void Menu::addItem(const char text[], fpCallback cb) {
    mItems[std::string(text)] = MenuItem(text, cb);
    // mItems.push_back(MenuItem(text, cb));
}

std::map<std::string, MenuItem> &Menu::items() { return mItems; }