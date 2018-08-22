#pragma once
#include "MenuItem.hpp"
#include "Point.hpp"
#include <string>
#include <vector>

class Menu {
  public:
    Menu();
    // ~Menu();

    void addItem(const char text[], fpCallback cb);

  private:
    std::vector<MenuItem> mItems;
};