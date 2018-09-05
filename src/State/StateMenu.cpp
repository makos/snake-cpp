#include "State/StateMenu.hpp"
#include "Event/Event.hpp"
#include "Game.hpp"
#include "Menu/Menu.hpp"
#include "Renderer/Subwindow.hpp"
#include "Renderer/Window.hpp"
#include "State/StatePlaying.hpp"

StateMenu::StateMenu(Game &game)
    : mGame(game),
      mWindowStack(),
      mMenu(std::make_unique<Menu>()),
      mItemSelected(0),
      mInternalState(InternalState::Main) {
    mWindowStack.push(
        std::make_unique<Window>(10, 16, (LINES / 2) - 5, (COLS / 2) - 8));
    topWindow().setBox(true);
    topWindow().setKeypad(true);
    topWindow().setDelay(false);
}

StateMenu::~StateMenu() {
    while (!mWindowStack.empty()) {
        mWindowStack.pop();
    }
}

void StateMenu::addItem(const char *text, Event event) {
    mMenu->addItem(text, event, this);
}

void StateMenu::addItem(const MenuItem &item) { mMenu->addItem(item); }

// Not really anything to update in a static menu.
void StateMenu::update() {}

void StateMenu::input() {
    int ch;
    ch = topWindow().getKey();

    switch (ch) {
        case 'q':
            if (mWindowStack.size() > 1) {
                mWindowStack.pop();
                mInternalState = InternalState::Main;
            } else {
                mGame.continueGame();
            }
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

// TODO: render contents based on which Window is visible (another State?)
void StateMenu::render(Renderer &renderer) {
    switch (mInternalState) {
        case InternalState::Main:
            renderMain();
            break;
        case InternalState::Settings:
            renderSettings();
            break;
    }
}

void StateMenu::renderMain() {
    topWindow().erase();
    int y = (topWindow().size().y / 2) - (mMenu->items().size() / 2);
    // - 4 because "Settings" (longest item in the menu) is 8 characters long,
    // so half of that.
    // TODO: make so the "- 4" is dynamically calculated.
    int x = (topWindow().size().x / 2) - 4;
    for (auto const &item : mMenu->items()) {
        item->id() == mItemSelected
            ? topWindow().print(y, x, item->text(), A_REVERSE)
            : topWindow().print(y, x, item->text());
        y++;
    }
    topWindow().refresh();
}

void StateMenu::renderSettings() {
    topWindow().erase();

    topWindow().print(1, 1, "settings");

    topWindow().refresh();
}

// FIXME: use a new Window rather than Subwindow because of how ncurses treats
// it. ncurses needs to call touchwin() on original window before refreshing
// subwindow, which is impossible with the stack.
void StateMenu::openSettings() {
    auto topWinPos = topWindow().position();
    auto settingsWin =
        std::make_unique<Window>(5, 10, topWinPos.y, topWinPos.x);
    settingsWin->setBox(true);
    mWindowStack.push(std::move(settingsWin));
    mInternalState = InternalState::Settings;
}

void StateMenu::onNotify(Event event) {
    switch (event) {
        case Event::ClickExit:
            mGame.setRunning(false);
            break;
        case Event::ClickContinue:
            // Clear the window stack
            while (!mWindowStack.empty()) {
                topWindow().clear();
                topWindow().refresh();
                mWindowStack.pop();
            }
            mGame.continueGame();
            break;
        case Event::ClickNew:
            mGame.newGame();
            break;
        case Event::ClickSettings:
            openSettings();
            break;
    }
}

IWindow &StateMenu::topWindow() { return *mWindowStack.top(); }