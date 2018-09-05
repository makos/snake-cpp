/*
 * StateMenu.hpp - Main Menu state logic. Creates and manages a Menu class.
 * Contains namespace Callback that holds callback functions to be used by
 * MenuItems.
 */
#pragma once
#include <memory>
#include <stack>
#include "Event/Observer.hpp"
#include "Event/Subject.hpp"
#include "Menu/Menu.hpp"
#include "Renderer/Window.hpp"
#include "State.hpp"
class Game;

class StateMenu : public IState, public Observer {
   public:
    StateMenu(Game &game);
    ~StateMenu();

    void input() final;
    void update() final;
    void render(Renderer &renderer) final;

    void addItem(const char *text, Event event);
<<<<<<< Updated upstream
    void addItem(const MenuItem &item);

    void onNotify(Event event) override;

   private:
    Game &mGame;
    std::stack<std::unique_ptr<Window>> mWindowStack;
    std::unique_ptr<Menu> mMenu;
    unsigned int mItemSelected;
=======

    void onNotify(Event event) final;

   private:
    Game &mGame;
    std::unique_ptr<IState> mInternalState;
    Subject mInternalStateNotifier;
>>>>>>> Stashed changes
};