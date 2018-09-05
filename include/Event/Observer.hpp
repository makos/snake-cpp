#pragma once
enum class Event;
#include "Event/MenuEventArgs.hpp"

class Observer {
   public:
    virtual ~Observer() = default;
    virtual void onNotify(Event event) {}
    virtual void onNotify(Event event, MenuEventArgs args) {}
};