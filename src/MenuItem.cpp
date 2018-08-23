#include "MenuItem.hpp"

MenuItem::MenuItem(const char text[], fpCallback cb, unsigned int id)
    : mText(std::string(text)), mCallback(cb), mId(id) {}

void MenuItem::click(Game &game) { mCallback(game); }

std::string MenuItem::text() { return mText; }

unsigned int MenuItem::id() { return mId; }