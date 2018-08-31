/*
 * MenuItem.hpp - class containing info about menu entries. The displayed text,
 * their internal ID and callback function.
 */
#pragma once
#include <string>
// #include "MenuEvent.hpp"
#include "State/Subject.hpp"
class Game;
enum MenuEvent;

// using fpCallback = void (*)(Game &);

class MenuItem {
   public:
    MenuItem(const char text[], MenuEvent event, Observer *observer,
             unsigned int id);

    void click();
    Subject &onClick();

    std::string text();
    unsigned int id();

   private:
    std::string mText;
    MenuEvent mEvent;
    Subject mOnClick;
    // fpCallback mCallback;
    unsigned int mId;
};