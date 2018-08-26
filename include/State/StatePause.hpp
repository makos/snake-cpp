#pragma once
#include "Menu/Menu.hpp"
#include "Render/Window.hpp"
#include "State.hpp"
#include <memory>
class Game;

class StatePause : public IState {
  public:
    StatePause(Game &game);

    void update();
    void input();
    void render(Render &render);

  private:
    Game &mGame;
    std::unique_ptr<Window> mWindow;
    std::unique_ptr<Menu> mMenu;
    unsigned int mItemSelected;
};
;
;