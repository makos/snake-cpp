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
#include "Renderer/IWindow.hpp"
#include "State.hpp"
class Game;

enum class InternalState { Main, Settings };

class StateMenu : public IState, public Observer {
   public:
    StateMenu(Game &game);
    // ~StateMenu();

    void input() final;
    void update() final;
    void render(Renderer &renderer) final;

    void addItem(const char *text, Event event);

    void onNotify(Event event) final;

   private:
    Game &mGame;
    std::unique_ptr<IState> mInternalState;
    Subject mInternalStateNotifier;
};