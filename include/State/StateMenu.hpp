#pragma once
#include "State.hpp"
class Game;

class StateMenu : public State {
  public:
    StateMenu(Game &game);

    void input() override;
    void update() override;
    void render(Render &render) override;

  private:
    Game *mGame;
    int mItemSelected;
};