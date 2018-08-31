#include "Menu/Menu.hpp"
#include "State/Observer.hpp"

Menu::Menu(Game &game) : mItems(), mGame(game) {}

// Add a menu item and connect it to a callback.
void Menu::addItem(const char text[], MenuEvent event, Observer &observer) {
    mItems.push_back(std::make_unique<MenuItem>(text, event, observer,
                                                (unsigned int)mItems.size()));
}

void Menu::addItem(const MenuItem &item) {
    mItems.push_back(std::make_unique<MenuItem>(item));
}

// Get the vector of all MenuItems attached.
std::vector<std::unique_ptr<MenuItem>> &Menu::items() { return mItems; }

// Fire the related callback.
void Menu::clickItem(unsigned int id) {
    if (id < mItems.size()) {
        mItems[id]->click(mGame);
    }
}