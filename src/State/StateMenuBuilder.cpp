#include "State/StateMenuBuilder.hpp"
#include "Game.hpp"

StateMenuBuilder::StateMenuBuilder(Game &game) : mGame(game), mItems() {}

void StateMenuBuilder::addItem(const char *text, fpCallback cb) {
    mItems.emplace_back(text, cb, (unsigned int)mItems.size());
}

StateMenu &StateMenuBuilder::build() {
    StateMenu menu(mGame);
    for (auto &item : mItems) {
        menu.addItem(item);
    }
    return menu;
}