#pragma once
#include "State.hpp"
class Game;

class StatePlaying : public IState {
  public:
    StatePlaying(Game &game);

    void update();
    void input();
    void render(Render &render);

  private:
    Game &mGame;
    std::unique_ptr<Window> mGameWindow;
};