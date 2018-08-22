#include "Menu.hpp"

void newClickEvent() {}

Menu::Menu() : mItems() {}

void Menu::addItem(const char text[], fpCallback cb) {
    mItems.push_back(MenuItem(text, cb));
}