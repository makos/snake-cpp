#include "Menu.hpp"

Menu::Menu(Game &game) : mItems(), mGame(game) {}

void Menu::addItem(const char text[], fpCallback cb) {
    mItems[std::string(text)] = std::make_unique<MenuItem>(text, cb);
}

std::map<std::string, std::unique_ptr<MenuItem>> &Menu::items() {
    return mItems;
}

void Menu::clickItem(const char text[]) {
    auto result = mItems.find(std::string(text));

    if (result != mItems.end()) {
        result->second->click(mGame);
    }
}