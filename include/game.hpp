#pragma once
#include "Render.hpp"

class Game {
  public:
    Game();
    ~Game();

    void run();

    bool isRunning();
    void setRunning(bool state);

  private:
    Render screen;
    int mScore;
    bool mIsRunning;
};