#include "Game.hpp"
#include "Event/Event.hpp"
#include "State/StateMenu.hpp"
#include "State/StatePlaying.hpp"

// Default constructor. Starts in main menu state.
Game::Game()
    : mRenderer(),
      mBoardSize(16, 30),
      mScore(0),
      mSpeed(150),
      mIsRunning(true),
      mShouldPop(false),
      mStateStack(),
      mRng() {
    mRng.seed(std::random_device()());
}

// Main loop.
void Game::run() {
    auto menu = std::make_unique<StateMenu>(*this);
    menu->addItem("New", Event::ClickNew);
    menu->addItem("Settings", Event::ClickSettings);
    menu->addItem("Exit", Event::ClickExit);
    // DEBUG
    Window debug(5, 10, 0, 0);

    mStateStack.push(std::move(menu));

    while (mIsRunning) {
        currentState().render(mRenderer);
        // DEBUG
        debug.print(0, 0, std::to_string(mStateStack.size()));
        debug.refresh();

        currentState().input();

        currentState().update();

        if (mShouldPop) {
            pop();
        }
    }
}

bool Game::isRunning() { return mIsRunning; }

void Game::setRunning(bool state) { mIsRunning = state; }

Renderer& Game::renderer() { return mRenderer; }

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
    if (mStateStack.size() > 1) mShouldPop = true;
}

void Game::pop() {
    mStateStack.pop();
    mShouldPop = false;
}

IState& Game::currentState() { return *mStateStack.top(); }

std::minstd_rand& Game::rng() { return mRng; }

Point Game::getBoardSize() { return mBoardSize; }

void Game::addScore(int n) { mScore += n; }

int Game::getScore() { return mScore; }

void Game::setSpeed(int speed) { mSpeed = speed; }

int Game::getSpeed() { return mSpeed; }
