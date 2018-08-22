#pragma once
#include "MenuItem.hpp"
#include "Point.hpp"
#include <map>
#include <string>
// #include <vector>

class Menu {
  public:
    Menu();
    // ~Menu();

    void addItem(const char text[], fpCallback cb);
    std::map<std::string, MenuItem> &items();

  private:
    // std::vector<MenuItem> mItems;
    std::map<std::string, MenuItem> mItems;
};