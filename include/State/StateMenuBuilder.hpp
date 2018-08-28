#pragma once
#include <vector>
#include "Menu/MenuItem.hpp"
#include "State/StateMenu.hpp"
class Game;

class StateMenuBuilder {
   public:
    StateMenuBuilder(Game &game);

    void addItem(const char *text, fpCallback cb);

    StateMenu &build();

   private:
    Game &mGame;
    std::vector<MenuItem> mItems;
}