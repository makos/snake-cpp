#include "State/StateMenu.hpp"
#include "Event/Event.hpp"
#include "Game.hpp"
#include "Menu/Menu.hpp"
<<<<<<< Updated upstream
=======
#include "Renderer/Subwindow.hpp"
#include "Renderer/Window.hpp"
#include "State/Menu/MainMenu.hpp"
>>>>>>> Stashed changes
#include "State/StatePlaying.hpp"

// Create two default menu items when the state is instantiated.
StateMenu::StateMenu(Game &game)
    : mGame(game),
<<<<<<< Updated upstream
      mWindowStack(),
      mMenu(std::make_unique<Menu>()),
      mItemSelected(0) {
    mWindowStack.push(
        std::make_unique<Window>(10, 16, (LINES / 2) - 5, (COLS / 2) - 8));
    mWindowStack.top()->setBox(true);
    mWindowStack.top()->setKeypad(true);
    mWindowStack.top()->setDelay(false);
=======
      mInternalState(std::make_unique<MainMenu>()),
      mInternalStateNotifier() {
    mInternalStateNotifier.addObserver(
        dynamic_cast<Observer *>(mInternalState.get()));
>>>>>>> Stashed changes
}

StateMenu::~StateMenu() {}

void StateMenu::addItem(const char *text, Event event) {
    mInternalStateNotifier.notify(Event::AddMenuItem,
                                  MenuEventArgs(text, event, this));
}

// Not really anything to update in a static menu.
void StateMenu::update() {}

<<<<<<< Updated upstream
void StateMenu::input() {
    int ch;
    ch = mWindowStack.top()->getKey();

    switch (ch) {
        case 'Q':
            mGame.setRunning(false);
            break;
        case KEY_UP:
            mItemSelected =
                (mItemSelected - 1) % (unsigned int)mMenu->items().size();
            break;
        case KEY_DOWN:
            mItemSelected =
                (mItemSelected + 1) % (unsigned int)mMenu->items().size();
            break;
        // KEY_ENTER in ncurses is actually the numpad Enter. So I had to use
        // '\n' (and '\r' just in case).
        case '\n':
        case '\r':
            mMenu->clickItem(mItemSelected);
            break;
    }
}

void StateMenu::render(Renderer &renderer) {
    mWindowStack.top()->erase();
    // int i = 1;
    int y = (mWindowStack.top()->size().y / 2) - (mMenu->items().size() / 2);
    // - 4 because "Settings" (longest item in the menu) is 8 characters long,
    // so half of that.
    int x = (mWindowStack.top()->size().x / 2) - 4;
    for (auto const &item : mMenu->items()) {
        item->id() == mItemSelected
            ? mWindowStack.top()->print(y, x, item->text(), A_REVERSE)
            : mWindowStack.top()->print(y, x, item->text());
        y++;
    }
    mWindowStack.top()->refresh();
}
=======
void StateMenu::input() { mInternalState->input(); }

// TODO: render contents based on which Window is visible (another State?)
void StateMenu::render(Renderer &renderer) { mInternalState->render(renderer); }
>>>>>>> Stashed changes

void StateMenu::onNotify(Event event) {
    switch (event) {
        case Event::ClickExit:
            mGame.setRunning(false);
            break;
        case Event::ClickContinue:
<<<<<<< Updated upstream
            mGame.popState();
            break;
        case Event::ClickNew:
            mGame.clearStates();
            mGame.pushState(std::make_unique<StatePlaying>(mGame));
            mGame.renderer().clearAll();
            mGame.renderer().refreshAll();
=======
            mGame.continueGame();
            break;
        case Event::ClickNew:
            mGame.newGame();
            break;
        case Event::ClickSettings:
>>>>>>> Stashed changes
            break;
    }
}