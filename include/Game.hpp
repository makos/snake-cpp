/*
 * Game.hpp - high-level game logic handling. States and main loop.
 */
#pragma once

#include "Render/Render.hpp"
#include "State/State.hpp"
#include <memory>
#include <stack>

class Game {
  public:
    Game();

    void run();

    bool isRunning();
    void setRunning(bool state);

    Render &renderer();

    void clearStates();
    void pushState(std::unique_ptr<IState> state);
    void popState();
    IState &currentState();

  private:
    void pop();

  private:
    Render mRenderer;
    int mScore;
    bool mIsRunning;
    bool mShouldPop;
    std::stack<std::unique_ptr<IState>> mStateStack;
};