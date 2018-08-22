#pragma once
#include "Render.hpp"
#include "State.hpp"
#include <memory>

class Game {
  public:
    Game();
    ~Game();

    void run();

    bool isRunning();
    void setRunning(bool state);

    Render &getScreen();

    void setState(std::unique_ptr<State> state);
    State &getState();

  private:
    Render mScreen;
    int mScore;
    bool mIsRunning;
    std::unique_ptr<State> mCurrentState;
};