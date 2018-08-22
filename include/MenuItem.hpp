#pragma once
#include <string>
class StateMenu;

using fpCallback = void (StateMenu::*)();

class MenuItem {
  public:
    MenuItem(const char text[], fpCallback cb);

    void click();

  private:
    std::string mText;
    fpCallback mCallback;
};