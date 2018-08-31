#pragma once
#include <vector>
#include "Observer.hpp"

class Subject {
   public:
    Subject();
    void addObserver(Observer *observer);
    void removeObserver(Observer *observer);
    void notify(Event event);

   private:
    std::vector<Observer *> mObservers;
};