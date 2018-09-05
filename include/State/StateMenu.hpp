/*
 * StateMenu.hpp - Main Menu state logic. Creates and manages a Menu class.
 * Contains namespace Callback that holds callback functions to be used by
 * MenuItems.
 */
#pragma once
#include <memory>
#include <stack>
#include "Event/Observer.hpp"
#include "Menu/Menu.hpp"
#include "Renderer/IWindow.hpp"
#include "State.hpp"
class Game;

enum class InternalState { Main, Settings };

class StateMenu : public IState, public Observer {
   public:
    StateMenu(Game &game);
    ~StateMenu();

    void input() override;
    void update() override;
    void render(Renderer &renderer) override;

    void addItem(const char *text, Event event);
    void addItem(const MenuItem &item);

    void onNotify(Event event) override;
    void registerObserver(Observer *observer);

   private:
    IWindow &topWindow();
    void openSettings();
    void renderMain();
    void renderSettings();

   private:
    Game &mGame;
    // std::unique_ptr<IState> mInternalState;
    std::stack<std::unique_ptr<IWindow>> mWindowStack;
    std::unique_ptr<Menu> mMenu;
    unsigned int mItemSelected;
    InternalState mInternalState;
};