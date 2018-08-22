#pragma once
#include <memory>
#include <string>
class StateMenu;
class Game;

// using fpCallback = void (StateMenu::*)();
typedef void (StateMenu::*fpCallback)(Game &);

class MenuItem {
  public:
    MenuItem(const char text[], fpCallback cb);

    void click();

  private:
    std::string mText;
    fpCallback mCallback;
};