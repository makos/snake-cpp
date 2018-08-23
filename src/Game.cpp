#include "Game.hpp"
#include "State/StateMenu.hpp"
#include "State/StatePlaying.hpp"

// Default constructor, creates a 20 by 20 game board ncurses window. Defaults
// to main menu state.
Game::Game()
    : mScreen(20, 20), mScore(0), mIsRunning(true),
      mCurrentState(std::make_unique<StateMenu>(*this)) {}

// I'm not sure it needs a destructor TBH.
Game::~Game() {}

// Main loop.
void Game::run() {
    mScreen.kpad(true);

    // Do an early first render pass to actually show the menu, otherwise it
    // would show a blank screen until user pressed some key.
    mCurrentState->render(mScreen);

    while (mIsRunning) {
        mCurrentState->input();

        mCurrentState->update();

        mCurrentState->render(mScreen);
    }
}

bool Game::isRunning() { return mIsRunning; }

void Game::setRunning(bool state) { mIsRunning = state; }

Render &Game::getScreen() { return mScreen; }

void Game::setState(std::unique_ptr<State> state) {
    mCurrentState = std::move(state);
}

State &Game::getState() { return *mCurrentState; }