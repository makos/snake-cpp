/*
 * Game.hpp - high-level game logic handling. States and main loop.
 */
#pragma once

#include "Renderer/Renderer.hpp"
#include "State/State.hpp"
#include <memory>
#include <stack>

class Game {
  public:
    Game();

    void run();

    bool isRunning();
    void setRunning(bool state);

    Renderer &renderer();

    void clearStates();
    void pushState(std::unique_ptr<IState> state);
    void popState();
    IState &currentState();

  private:
    void pop();

  private:
    Renderer mRenderer;
    int mScore;
    bool mIsRunning;
    bool mShouldPop;
    std::stack<std::unique_ptr<IState>> mStateStack;
};