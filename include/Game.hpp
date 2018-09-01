/*
 * Game.hpp - high-level game logic handling. States and main loop.
 */
#pragma once

#include <memory>
#include <random>
#include <stack>
#include "Event/Observer.hpp"
#include "Renderer/Renderer.hpp"
#include "State/State.hpp"
#include "Util/Point.hpp"

class Game {
   public:
    Game();

    void run();

    bool isRunning();
    void setRunning(bool state);

    Renderer &renderer();
    Point getBoardSize();

    void clearStates();
    void pushState(std::unique_ptr<IState> state);
    void popState();
    IState &currentState();
    std::minstd_rand &rng();

    void addScore(int n);
    int getScore();

    void setSpeed(int speed);
    int getSpeed();

   private:
    void pop();

   private:
    Renderer mRenderer;
    Point mBoardSize;
    int mScore;
    int mSpeed;
    bool mIsRunning;
    bool mShouldPop;
    std::stack<std::unique_ptr<IState>> mStateStack;
    std::minstd_rand mRng;
};