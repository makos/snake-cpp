/*
 * MenuItem.hpp - class containing info about menu entries. The displayed text,
 * their internal ID and callback function.
 */
#pragma once
#include <string>
#include "Event/Subject.hpp"
class Game;
enum class Event;

class MenuItem {
   public:
    MenuItem(const char text[], Event event, Observer *observer,
             unsigned int id);

    void click();

    std::string text();
    unsigned int id();

   private:
    std::string mText;
    Event mEvent;
    Subject mSubjectOnClick;
    unsigned int mId;
};