#pragma once
enum class Event;
class Observer;

class MenuEventArgs {
   public:
    MenuEventArgs(const char *tText, Event tEvent, Observer *tObserver);

   public:
    const char *text;
    Event event;
    Observer *observer;
};