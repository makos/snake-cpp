#pragma once
#include "Player/Player.hpp"
#include "Renderer/Window.hpp"
#include "State.hpp"
#include <memory>
class Game;

class StatePlaying : public IState {
  public:
    StatePlaying(Game &game);
    ~StatePlaying();

    void update();
    void input();
    void render(Renderer &renderer);

  private:
    Game &mGame;
    std::unique_ptr<Window> mGameWindow;
    Player mPlayer;
};