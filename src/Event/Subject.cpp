#include "Event/Subject.hpp"
#include "Event/Event.hpp"

Subject::Subject() : mObservers() {}

Subject::Subject(Observer *observer) : mObservers(1, observer) {}

void Subject::addObserver(Observer *observer) {
    mObservers.push_back(observer);
}

void Subject::removeObserver(Observer *observer) {
    for (auto it = mObservers.begin(); it != mObservers.end();) {
        if (*it == observer) {
            mObservers.erase(it);
        } else {
            ++it;
        }
    }
}

void Subject::notify(Event event) {
    for (auto observer : mObservers) {
        observer->onNotify(event);
    }
}