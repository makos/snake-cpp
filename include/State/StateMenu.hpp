/*
 * StateMenu.hpp - Main Menu state logic. Creates and manages a Menu class.
 * Contains namespace Callback that holds callback functions to be used by
 * MenuItems.
 */
#pragma once
#include <memory>
#include <stack>
#include "Menu/Menu.hpp"
#include "Renderer/Window.hpp"
#include "State.hpp"
class Game;

class StateMenu : public IState
{
public:
  StateMenu(Game &game);
  ~StateMenu();

  void input() override;
  void update() override;
  void render(Renderer &renderer) override;

  void addItem(const char *text, fpCallback callback);
  void addItem(const MenuItem &item);

private:
  Game &mGame;
  // std::unique_ptr<Window> mWindow;
  std::stack<std::unique_ptr<Window>> mWindowStack;
  std::unique_ptr<Menu> mMenu;
  unsigned int mItemSelected;
};