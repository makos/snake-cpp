#include "game.hpp"
#include "point.hpp"
#include <curses.h>

Game::Game() {
    mBoardSize = new Point(10, 20);
    // mScoreWindowSize = new Point(1, 10);
    mMenuWindowSize = new Point(10, 10);
    mBoardPos = new Point(1, 1);
    // mScoreWindowPos = new Point(0, 1);
    mMenuWindowPos = new Point(0, 0);

    mBoardWindow =
        newwin(mBoardSize->y, mBoardSize->x, mBoardPos->y, mBoardPos->x);
    // mScoreWindow = newwin(mScoreWindowSize->y, mScoreWindowSize->x,
    //                       mScoreWindowPos->y, mScoreWindowPos->x);
    mMenuWindow = newwin(mMenuWindowSize->y, mMenuWindowSize->x,
                         mMenuWindowPos->y, mMenuWindowPos->x);

    mWinStack.push(mMenuWindow);
    mWinStack.push(mBoardWindow);

    mIsRunning = true;
}

Game::~Game() {
    for (std::size_t i = 0; i < mWinStack.size(); i++) {
        delwin(mWinStack.top());
        mWinStack.pop();
    }
}

int Game::getStackSize() { return (int)mWinStack.size(); }

void Game::refreshTopWindow() { wrefresh(mWinStack.top()); }

void Game::pushWindow(WINDOW *win) { mWinStack.push(win); }

WINDOW *Game::popWindow() {
    WINDOW *temp = mWinStack.top();
    mWinStack.pop();
    return temp;
}

WINDOW *Game::getTopWindow() { return mWinStack.top(); }

void Game::getInput() {
    int ch;
    ch = wgetch(mWinStack.top());

    switch (ch) {
    case 'Q':
        mIsRunning = false;
        break;
    case 'd':
        mWinStack.pop();
        break;
    }
}

bool Game::isRunning() { return mIsRunning; }

void Game::setRunning(bool state) { mIsRunning = state; }