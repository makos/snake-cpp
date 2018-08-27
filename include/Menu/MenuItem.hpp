/*
 * MenuItem.hpp - class containing info about menu entries. The displayed text,
 * their internal ID and callback function.
 */
#pragma once
#include <string>
class Game;

using fpCallback = void (*)(Game &);

class MenuItem {
   public:
    MenuItem(const char text[], fpCallback cb, unsigned int id);

    void click(Game &game);

    std::string text();
    unsigned int id();

   private:
    std::string mText;
    fpCallback mCallback;
    unsigned int mId;
};