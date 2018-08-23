/*
 * Game.hpp - high-level game logic handling. States and main loop.
 */
#pragma once

#include "Render/Render.hpp"
#include "State/State.hpp"
#include <memory>

class Game {
  public:
    Game();
    ~Game();

    void run();

    bool isRunning();
    void setRunning(bool state);

    Render &getScreen();

    void setState(std::unique_ptr<IState> state);
    IState &getState();

  private:
    Render mScreen;
    int mScore;
    bool mIsRunning;
    std::unique_ptr<IState> mCurrentState;
};