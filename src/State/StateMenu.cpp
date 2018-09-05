#include "State/StateMenu.hpp"
#include "Event/Event.hpp"
#include "Game.hpp"
#include "Menu/Menu.hpp"
#include "Renderer/Subwindow.hpp"
#include "Renderer/Window.hpp"
#include "State/Menu/MainMenu.hpp"
#include "State/Menu/SettingsDialog.hpp"
#include "State/StatePlaying.hpp"

StateMenu::StateMenu(Game &game)
    : mGame(game),
      mInternalState(std::make_unique<MainMenu>()),
      mInternalStateNotifier() {
    mInternalStateNotifier.addObserver(
        dynamic_cast<Observer *>(mInternalState.get()));
}

// StateMenu::~StateMenu() {}

void StateMenu::addItem(const char *text, Event event) {
    mInternalStateNotifier.notify(Event::AddMenuItem,
                                  MenuEventArgs(text, event, this));
}

// Not really anything to update in a static menu.
void StateMenu::update() {}

void StateMenu::input() { mInternalState->input(); }

// TODO: render contents based on which Window is visible (another State?)
void StateMenu::render(Renderer &renderer) { mInternalState->render(renderer); }

void StateMenu::onNotify(Event event) {
    switch (event) {
        case Event::ClickExit:
            mGame.setRunning(false);
            break;
        case Event::ClickContinue:
            mGame.continueGame();
            break;
        case Event::ClickNew:
            mGame.newGame();
            break;
        case Event::ClickSettings:
            mInternalState = std::make_unique<SettingsDialog>();
            break;
    }
}