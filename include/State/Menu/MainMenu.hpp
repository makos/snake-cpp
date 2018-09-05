#pragma once
#include <memory>
#include "Event/MenuEventArgs.hpp"
#include "Event/Observer.hpp"
#include "Menu/Menu.hpp"
#include "Renderer/Window.hpp"
#include "State/State.hpp"
enum class Event;

class MainMenu : public IState, public Observer {
   public:
    MainMenu();
    // ~MainMenu();

    void update() final;
    void input() final;
    void render(Renderer& renderer) final;

    void onNotify(Event event, MenuEventArgs args) final;

   private:
    std::unique_ptr<Menu> mMenu;
    std::unique_ptr<Window> mWindow;
    unsigned int mItemSelected;
};