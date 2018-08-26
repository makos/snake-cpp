#pragma once
#include "Menu/Menu.hpp"
#include "Player/Player.hpp"
#include "Renderer/Window.hpp"
#include "State.hpp"
#include <memory>
class Game;

class StatePause : public IState {
  public:
    StatePause(Game &game);
    ~StatePause();

    void update();
    void input();
    void render(Renderer &renderer);

  private:
    Game &mGame;
    std::unique_ptr<Window> mWindow;
    std::unique_ptr<Menu> mMenu;
    unsigned int mItemSelected;
    Player mPlayer;
};