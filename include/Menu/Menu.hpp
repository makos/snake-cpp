/*
 * Menu.hpp - class handling MenuItems and their callbacks.
 */
#pragma once
#include <memory>
#include <vector>
#include "Menu/MenuItem.hpp"
class Game;

class Menu {
   public:
    Menu(Game &game);

    void addItem(const char text[], fpCallback cb);
    void addItem(const MenuItem &item);
    std::vector<std::unique_ptr<MenuItem>> &items();
    void clickItem(unsigned int id);

   private:
    std::vector<std::unique_ptr<MenuItem>> mItems;
    Game &mGame;
};