#pragma once
#include "State.hpp"
class Game;

class StateMenu : public State {
  public:
    StateMenu(Game &game);

    void update();
    void input();
    void render(Render &render);

  private:
    Game *mGame;
};