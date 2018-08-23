#pragma once
#include <string>
class Game;

using fpCallback = void (*)(Game &);

class MenuItem {
  public:
    MenuItem(const char text[], fpCallback cb);

    void click(Game &game);

  private:
    std::string mText;
    fpCallback mCallback;
};