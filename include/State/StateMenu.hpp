/*
 * StateMenu.hpp - Main Menu state logic. Creates and manages a Menu class.
 * Contains namespace Callback that holds callback functions to be used by
 * MenuItems.
 */
#pragma once
#include <memory>
#include "Menu/Menu.hpp"
#include "Renderer/Window.hpp"
#include "State.hpp"
class Game;

class StateMenu : public IState {
   public:
    StateMenu(Game &game);
    ~StateMenu();

    void input();
    void update();
    void render(Renderer &renderer);

    void addItem(const char *text, fpCallback callback);

   private:
    Game &mGame;
    std::unique_ptr<Window> mWindow;
    std::unique_ptr<Menu> mMenu;
    unsigned int mItemSelected;
};