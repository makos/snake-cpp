#include "Menu/MenuItem.hpp"
#include "Event/Event.hpp"
#include "Event/Observer.hpp"

MenuItem::MenuItem(const char text[], Event event, Observer *observer,
                   unsigned int id)
    : mText(std::string(text)), mEvent(event), mOnClick(), mId(id) {
    mOnClick.addObserver(observer);
}

// Fire the callback.
void MenuItem::click() { mOnClick.notify(mEvent); }

Subject &MenuItem::onClick() { return mOnClick; }

// Displayed text in the menu.
std::string MenuItem::text() { return mText; }

// ID of the MenuItem (is same as the vector index in Menu class).
unsigned int MenuItem::id() { return mId; }