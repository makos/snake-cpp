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

    void input() override;
    void update() override;
    void render(Renderer &renderer) override;

    void addItem(const char *text, Event event);
    void addItem(const MenuItem &item);

    void onNotify(Event event) override;
    void registerObserver(Observer *observer);

   private:
    Game &mGame;
    std::stack<std::unique_ptr<Window>> mWindowStack;
    std::unique_ptr<Menu> mMenu;
    Subject mEventSubject;
    unsigned int mItemSelected;
};