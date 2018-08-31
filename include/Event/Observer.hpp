#pragma once
enum class Event;

class Observer {
   public:
    virtual ~Observer() = default;
    virtual void onNotify(Event event) = 0;
};