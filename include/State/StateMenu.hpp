/*
 * StateMenu.hpp - Main Menu state logic. Creates and manages a Menu class.
 * Contains namespace Callback that holds callback functions to be used by
 * MenuItems.
 */
#pragma once
#include "Menu/Menu.hpp"
#include "Render/Window.hpp"
#include "State.hpp"
#include <memory>
class Game;
// class Menu;

class StateMenu : public IState {
  public:
    StateMenu(Game &game);

    void input();
    void update();
    void render(Render &render);

  private:
    Game &mGame;
    std::unique_ptr<Window> mWindow;
    std::unique_ptr<Menu> mMenu;
    unsigned int mItemSelected;
};