#include "Menu.hpp"

Menu::Menu(Game &game) : mItems(), mGame(game) {}

void Menu::addItem(const char text[], fpCallback cb) {
    unsigned int temp_id = (unsigned int)mItems.size();
    mItems.push_back(std::make_unique<MenuItem>(text, cb, temp_id));
}

std::vector<std::unique_ptr<MenuItem>> &Menu::items() { return mItems; }

void Menu::clickItem(unsigned int id) {
    if (id < mItems.size()) {
        mItems[id]->click(mGame);
    }
}