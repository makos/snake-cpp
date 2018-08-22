#pragma once
#include "state.hpp"
class Game;

class StatePlaying : public State {
  public:
    StatePlaying(Game &game);

    void update() override;
    void input() override;
    void render(Render &render) override;

  private:
    Game *mGame;
};