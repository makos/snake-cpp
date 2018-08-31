/*
 * Menu.hpp - class handling MenuItems and their callbacks.
 */
#pragma once
#include <memory>
#include <vector>
#include "Menu/MenuItem.hpp"
class Game;
class Observer;

class Menu {
   public:
    Menu();

    void addItem(const char text[], MenuEvent event, Observer *observer);
    void addItem(const MenuItem &item);
    std::vector<std::unique_ptr<MenuItem>> &items();
    void clickItem(unsigned int id);

   private:
    std::vector<std::unique_ptr<MenuItem>> mItems;
};