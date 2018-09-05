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

    IState &currentState();
    std::minstd_rand &rng();

    void addScore(const int n);
    int getScore();

    void setSpeed(const int speed);
    int getSpeed();

    void pauseMenu();
    void newGame();
    void continueGame();
    void gameOver();

   private:
    void clearStates();
    void pushState(std::unique_ptr<IState> state);
    void popState();
    void pop();
    void push();

   private:
    Renderer mRenderer;
    Point mBoardSize;
    int mScore;
    int mSpeed;
    bool mIsRunning;
    bool mShouldPop;
    bool mShouldPush;
    std::unique_ptr<IState> mToPush;
    std::stack<std::unique_ptr<IState>> mStateStack;
    std::minstd_rand mRng;
};