/*
 * Game.hpp - high-level game logic handling. States and main loop.
 */
#pragma once
// TODO: look at StatePlaying.cpp, line 48

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

<<<<<<< HEAD
=======
    void game_over();

    void onNotify(Event event) override;

>>>>>>> 54d07c734ba041957d69638ce6480a413a78fdb8
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