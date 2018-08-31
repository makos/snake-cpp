#pragma once
#include "Menu/MenuEvent.hpp"

class Observer {
   public:
    virtual ~Observer() = default;
    virtual void onNotify(MenuEvent event) = 0;
};