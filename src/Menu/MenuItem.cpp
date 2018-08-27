#include "Menu/MenuItem.hpp"

MenuItem::MenuItem(const char text[], fpCallback cb, unsigned int id)
    : mText(std::string(text)), mCallback(cb), mId(id) {}

// Fire the callback.
void MenuItem::click(Game &game) { mCallback(game); }

// Displayed text in the menu.
std::string MenuItem::text() { return mText; }

// ID of the MenuItem (is same as the vector index in Menu class).
unsigned int MenuItem::id() { return mId; }