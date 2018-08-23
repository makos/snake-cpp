#include "Game.hpp"
#include "State/StateMenu.hpp"
#include "State/StatePlaying.hpp"

Game::Game()
    : mScreen(20, 20), mScore(0), mIsRunning(true),
      mCurrentState(std::make_unique<StateMenu>(*this)) {}

Game::~Game() {}

// Main loop
void Game::run() {
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