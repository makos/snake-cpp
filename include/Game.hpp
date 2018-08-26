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

    Render &getScreen();

    // void setState(std::unique_ptr<IState> state);
    void pushState(std::unique_ptr<IState> state);
    void popState();
    IState &currentState();

  private:
    void pop();

  private:
    Render mScreen;
    int mScore;
    bool mIsRunning;
    bool mShouldPop;
    // std::unique_ptr<IState> mCurrentState;
    std::stack<std::unique_ptr<IState>> mStateStack;
};