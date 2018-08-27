/*
 * StatePlaying.hpp - where the actions takes place. Game rendering, player
 * movement, scoring etc. happen here.
 */
#pragma once
#include "Entities/Player.hpp"
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

    bool canMove();

  private:
    Game &mGame;
    std::unique_ptr<Window> mGameWindow;
    Player mPlayer;
};