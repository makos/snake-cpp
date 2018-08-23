#pragma once
#include "MenuItem.hpp"
#include <iostream>
#include <map>
#include <memory>
#include <string>
class Game;

class Menu {
  public:
    Menu(Game &game);
    // ~Menu();

    void addItem(const char text[], fpCallback cb);
    std::map<std::string, std::unique_ptr<MenuItem>> &items();
    void clickItem(const char text[]);

  private:
    // std::vector<MenuItem> mItems;
    std::map<std::string, std::unique_ptr<MenuItem>> mItems;
    Game &mGame;
};