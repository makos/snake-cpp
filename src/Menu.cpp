#include "Menu.hpp"

Menu::Menu(Game &game) : mItems(), mGame(game) {}

void Menu::addItem(const char text[], fpCallback cb) {
    mItems[std::string(text)] = std::make_unique<MenuItem>(text, cb);
    // mItems.push_back(MenuItem(text, cb));
}

std::map<std::string, std::unique_ptr<MenuItem>> &Menu::items() {
    return mItems;
}

void Menu::clickItem(const char text[]) {
    std::cout << "clicking item " << text << std::endl;

    auto result = mItems.find(std::string(text));
    if (result != mItems.end()) {
        std::cout << "found item " << result->first << std::endl;
        result->second->click(mGame);
    }
}