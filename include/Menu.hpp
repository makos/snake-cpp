#pragma once
#include "MenuItem.hpp"
#include <iostream>
// #include <map>
#include <memory>
#include <string>
#include <vector>
class Game;

class Menu {
  public:
    Menu(Game &game);

    void addItem(const char text[], fpCallback cb);
    std::vector<std::unique_ptr<MenuItem>> &items();
    // std::map<int, std::unique_ptr<MenuItem>> &items();
    void clickItem(unsigned int id);

  private:
    // std::map<int, std::unique_ptr<MenuItem>> mItems;
    std::vector<std::unique_ptr<MenuItem>> mItems;
    Game &mGame;
};