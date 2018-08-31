#pragma once
enum MenuEvent;

class Observer {
   public:
    virtual ~Observer() = default;
    virtual void onNotify(MenuEvent event) = 0;
};