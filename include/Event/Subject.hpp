#pragma once
#include <vector>
<<<<<<< Updated upstream
#include "Observer.hpp"
=======
#include "Event/MenuEventArgs.hpp"
#include "Event/Observer.hpp"
>>>>>>> Stashed changes

class Subject {
   public:
    Subject();
    void addObserver(Observer *observer);
    void removeObserver(Observer *observer);
    void notify(Event event);
    void notify(Event event, MenuEventArgs args);

   private:
    std::vector<Observer *> mObservers;
};