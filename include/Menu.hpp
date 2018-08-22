#pragma once
#include "Point.hpp"
#include <string>

class Menu {
  public:
    Menu(Point pos);
    ~Menu();

    void addItem(std::string);

  private:
};