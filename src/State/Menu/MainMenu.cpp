#include "State/Menu/MainMenu.hpp"
#include "Event/Event.hpp"
#include "Renderer/Renderer.hpp"

MainMenu::MainMenu()
    : mMenu(std::make_unique<Menu>()),
      mWindow(
          std::make_unique<Window>(10, 16, (LINES / 2) - 5, (COLS / 2) - 8)),
      mItemSelected(0) {
    mWindow->setBox(true);
    mWindow->setKeypad(true);
    mWindow->setDelay(true);
}

// MainMenu::~MainMenu() {}

void MainMenu::update() {}

void MainMenu::input() {
    int ch;
    ch = mWindow->getKey();

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

void MainMenu::render(Renderer& renderer) {
    mWindow->erase();
    int y = (mWindow->size().y / 2) - (mMenu->items().size() / 2);
    // - 4 because "Settings" (longest item in the menu) is 8 characters long,
    // so half of that.
    // TODO: make so the "- 4" is dynamically calculated.
    int x = (mWindow->size().x / 2) - 4;
    for (auto const& item : mMenu->items()) {
        item->id() == mItemSelected
            ? mWindow->print(y, x, item->text(), A_REVERSE)
            : mWindow->print(y, x, item->text());
        y++;
    }
    mWindow->refresh();
}

void MainMenu::onNotify(Event event, MenuEventArgs args) {
    switch (event) {
        case Event::AddMenuItem:
            mMenu->addItem(args.text, args.event, args.observer);
    }
}