#include "State/Menu/SettingsDialog.hpp"
#include "Event/Event.hpp"

SettingsDialog::SettingsDialog()
    : mWindow(
          std::make_unique<Window>(10, 10, (LINES / 2) - 5, (COLS / 2) - 5)) {
    mWindow->setBox(true);
    mWindow->setDelay(true);
    mWindow->setKeypad(true);
}

void SettingsDialog::update() {}

void SettingsDialog::input() {
    int ch;
    ch = mWindow->getKey();

    switch (ch) {
        case 'q':
            exit(0);
            break;
    }
}

void SettingsDialog::render(Renderer& renderer) {
    mWindow->erase();

    mWindow->print(2, 2, "test");

    mWindow->refresh();
}

void SettingsDialog::onNotify(Event event, MenuEventArgs args) {
    switch (event) {
        case Event::AddMenuItem:
            break;
    }
}