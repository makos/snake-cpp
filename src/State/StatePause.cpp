#include "State/StatePause.hpp"
#include "Game.hpp"
#include "State/Callback.hpp"

StatePause::StatePause(Game &game)
    : mGame(game),
      mWindow(std::make_unique<Window>(8, 14, (LINES - 4) / 2, (COLS - 7) / 2)),
      mMenu(std::make_unique<Menu>(game)), mItemSelected(0) {
    mMenu->addItem("* Continue *", Callback::continueClicked);
    mMenu->addItem("* New *", Callback::newClicked);
    mMenu->addItem("* Exit *", Callback::exitClicked);
    mWindow->setKeypad(true);
    mWindow->setBox(true);
}

StatePause::~StatePause() {
    mGame.renderer().clearAll();
    mGame.renderer().refreshAll();
    mWindow->clear();
}

void StatePause::update() {}

void StatePause::input() {
    int ch;
    ch = mWindow->getKey();

    switch (ch) {
    case 'q':
        mGame.popState();
        break;
    case KEY_UP:
        mItemSelected =
            (mItemSelected - 1) % (unsigned int)mMenu->items().size();
        break;
    case KEY_DOWN:
        mItemSelected =
            (mItemSelected + 1) % (unsigned int)mMenu->items().size();
        break;
    case '\n':
    case '\r':
        mMenu->clickItem(mItemSelected);
        break;
    }
}

void StatePause::render(Renderer &renderer) {
    mWindow->erase();
    int i = 1;
    for (auto const &item : mMenu->items()) {
        item->id() == mItemSelected
            ? renderer.print(*mWindow, i, 1, item->text(), A_REVERSE)
            : renderer.print(*mWindow, i, 1, item->text());
        i += 2;
    }
    mWindow->refresh();
}