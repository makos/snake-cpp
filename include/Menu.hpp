/*
 * Menu.hpp - class handling MenuItems and their callbacks.
 */
#pragma once
#include "MenuItem.hpp"
#include <memory>
#include <vector>
class Game;

class Menu {
  public:
    Menu(Game &game);

    void addItem(const char text[], fpCallback cb);
    std::vector<std::unique_ptr<MenuItem>> &items();
    void clickItem(unsigned int id);

  private:
    std::vector<std::unique_ptr<MenuItem>> mItems;
    Game &mGame;
};