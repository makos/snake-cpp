#include "Menu/MenuItem.hpp"
#include "Event/Event.hpp"
#include "Event/Observer.hpp"

MenuItem::MenuItem(const char text[], Event event, Observer *observer,
                   unsigned int id)
    : mText(std::string(text)), mEvent(event), mSubjectOnClick(), mId(id) {
    mSubjectOnClick.addObserver(observer);
}

// Fire the callback.
void MenuItem::click() { mSubjectOnClick.notify(mEvent); }

// Displayed text in the menu.
std::string MenuItem::text() { return mText; }

// ID of the MenuItem (is same as the vector index in Menu class).
unsigned int MenuItem::id() { return mId; }