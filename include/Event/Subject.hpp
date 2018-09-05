#pragma once
#include <vector>
#include "Event/MenuEventArgs.hpp"
#include "Event/Observer.hpp"

class Subject {
   public:
    Subject();
    Subject(Observer *observer);
    void addObserver(Observer *observer);
    void removeObserver(Observer *observer);
    void notify(Event event);
    void notify(Event event, MenuEventArgs args);

   private:
    std::vector<Observer *> mObservers;
};