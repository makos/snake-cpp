/*
 * StatePause.hpp - pause (in-game) menu logic. Very similar to Main Menu; maybe
 * there's a way to generalize this enough to not require two classes?
 */
#pragma once
#include "Menu/Menu.hpp"
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
};