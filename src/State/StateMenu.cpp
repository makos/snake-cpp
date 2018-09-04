#include "State/StateMenu.hpp"
#include "Event/Event.hpp"
#include "Game.hpp"
#include "Menu/Menu.hpp"
#include "State/StatePlaying.hpp"

StateMenu::StateMenu(Game &game)
    : mGame(game),
      mWindowStack(),
      mMenu(std::make_unique<Menu>()),
      mEventSubject(),
      mItemSelected(0) {
    mWindowStack.push(
        std::make_unique<Window>(10, 16, (LINES / 2) - 5, (COLS / 2) - 8));
    mWindowStack.top()->setBox(true);
    mWindowStack.top()->setKeypad(true);
    mWindowStack.top()->setDelay(false);
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
    ch = mWindowStack.top()->getKey();

    switch (ch) {
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

void StateMenu::onNotify(Event event) {
    switch (event) {
        case Event::ClickExit:
            mGame.setRunning(false);
            break;
        case Event::ClickContinue:
            // Clear the window stack
            while (mWindowStack.size() > 0) {
                mWindowStack.top()->clear();
                mWindowStack.top()->refresh();
                mWindowStack.pop();
            }
            mGame.continueGame();
            break;
        case Event::ClickNew:
            mGame.newGame();
            break;
    }
}
