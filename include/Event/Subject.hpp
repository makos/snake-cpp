#pragma once
#include <vector>
#include "Event/Observer.hpp"

class Subject {
   public:
    Subject();
    Subject(Observer *observer);
    void addObserver(Observer *observer);
    void removeObserver(Observer *observer);
    void notify(Event event);

   private:
    std::vector<Observer *> mObservers;
};