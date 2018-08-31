/*
 * MenuItem.hpp - class containing info about menu entries. The displayed text,
 * their internal ID and callback function.
 */
#pragma once
#include <string>
// #include "MenuEvent.hpp"
#include "Event/Subject.hpp"
class Game;
// class MenuEvent;
enum class Event;

// using fpCallback = void (*)(Game &);

class MenuItem {
   public:
    MenuItem(const char text[], Event event, Observer *observer,
             unsigned int id);

    void click();
    Subject &onClick();

    std::string text();
    unsigned int id();

   private:
    std::string mText;
    Event mEvent;
    Subject mOnClick;
    // fpCallback mCallback;
    unsigned int mId;
};