#include "Game.hpp"
#include <chrono>
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
      mRng(std::chrono::system_clock::to_time_t(
          std::chrono::system_clock::now())) {
    // mRng.seed(
    //     std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
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

void Game::gameOver() {}

void Game::continueGame() {
    mRenderer.clearAll();
    mRenderer.refreshAll();
    popState();
}

void Game::pauseMenu() {
    auto pauseMenu = std::make_unique<StateMenu>(*this);
    pauseMenu->addItem("Continue", Event::ClickContinue);
    pauseMenu->addItem("New", Event::ClickNew);
    pauseMenu->addItem("Settings", Event::ClickSettings);
    pauseMenu->addItem("Exit", Event::ClickExit);

    pushState(std::move(pauseMenu));
}

void Game::newGame() {
    mScore = 0;
    clearStates();
    pushState(std::make_unique<StatePlaying>(*this));
    mRenderer.clearAll();
    mRenderer.refreshAll();
}

IState& Game::currentState() { return *mStateStack.top(); }

std::minstd_rand& Game::rng() { return mRng; }

Point Game::getBoardSize() { return mBoardSize; }

void Game::addScore(int n) { mScore += n; }

int Game::getScore() { return mScore; }

void Game::setSpeed(int speed) { mSpeed = speed; }

int Game::getSpeed() { return mSpeed; }
