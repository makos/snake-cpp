#pragma once
// #include <memory>
#include <string>
// class StateMenu;
class Game;

// using fpCallback = void (StateMenu::*)();
// typedef void (StateMenu::*fpCallback)(Game &);
using fpCallback = void (*)(Game &);

class MenuItem {
  public:
    MenuItem(const char text[], fpCallback cb);

    void click(Game &game);

  private:
    std::string mText;
    fpCallback mCallback;
};