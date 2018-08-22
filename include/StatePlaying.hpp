#pragma once
#include "state.hpp"
class Game;

class StatePlaying : public State {
  public:
    StatePlaying(Game &game);

    void update();
    void input();
    void render(Render &render);

  private:
    Game *mGame;
};