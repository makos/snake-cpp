#pragma once
#include <memory>
#include "Event/Observer.hpp"
#include "Renderer/Window.hpp"
#include "State/State.hpp"

class SettingsDialog : public IState, public Observer {
   public:
    SettingsDialog();

    void update() final;
    void input() final;
    void render(Renderer& renderer) final;

    void onNotify(Event event, MenuEventArgs args) final;

   private:
    std::unique_ptr<Window> mWindow;
};