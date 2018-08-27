#include "Game.hpp"
#include "State/StateMenu.hpp"
#include "State/StatePlaying.hpp"

// Default constructor. Starts in main menu state.
Game::Game()
    : mRenderer(), mBoardSize(16, 30), mScore(0), mIsRunning(true),
      mShouldPop(false), mStateStack(), mRng() {
    mRng.seed(std::random_device()());
}

// Main loop.
void Game::run() {
    mStateStack.push(std::make_unique<StateMenu>(*this));

    while (mIsRunning) {
        currentState().render(mRenderer);

        currentState().input();

        currentState().update();

        if (mShouldPop) {
            pop();
        }
    }
}

bool Game::isRunning() { return mIsRunning; }

void Game::setRunning(bool state) { mIsRunning = state; }

Renderer &Game::renderer() { return mRenderer; }

// Pop all states from the stack except the first one (Main Menu).
void Game::clearStates() {
    while (mStateStack.size() > 1) {
        mStateStack.pop();
    }
}

void Game::pushState(std::unique_ptr<IState> state) {
    mStateStack.push(std::move(state));
}

void Game::popState() {
    if (mStateStack.size() > 1)
        mShouldPop = true;
}

void Game::pop() {
    mStateStack.pop();
    mShouldPop = false;
}

IState &Game::currentState() { return *mStateStack.top(); }

std::minstd_rand &Game::rng() { return mRng; }

Point Game::getBoardSize() { return mBoardSize; }

void Game::addScore(int n) { mScore += n; }

int Game::getScore() { return mScore; }