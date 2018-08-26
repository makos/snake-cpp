#include "Game.hpp"
#include "State/StateMenu.hpp"
#include "State/StatePlaying.hpp"

// Default constructor. Starts in main menu state.
Game::Game()
    : mScreen(), mScore(0), mIsRunning(true), mShouldPop(false), mStateStack() {
}
//   mCurrentState(std::make_unique<StateMenu>(*this)) {}

// Main loop.
void Game::run() {
    mStateStack.push(std::make_unique<StateMenu>(*this));
    // mScreen.kpad(stdscr, true);
    // TODO: move this to Window
    // keypad(stdscr, true);

    // Do an early first render pass to actually show the menu, otherwise it
    // would show a blank screen until user pressed some key.
    currentState().render(mScreen);
    // mCurrentState->render(mScreen);

    while (mIsRunning) {
        // mCurrentState->render(mScreen);
        currentState().render(mScreen);

        // mCurrentState->input();
        currentState().input();

        // mCurrentState->update();
        currentState().update();

        if (mShouldPop)
            pop();
    }
}

bool Game::isRunning() { return mIsRunning; }

void Game::setRunning(bool state) { mIsRunning = state; }

Render &Game::getScreen() { return mScreen; }

// void Game::setState(std::unique_ptr<IState> state) {
//     mCurrentState = std::move(state);
// }

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