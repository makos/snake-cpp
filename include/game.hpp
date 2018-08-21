#pragma once

#include <stack>

typedef struct _win WINDOW;
class Point;

class Game {
  public:
    Game();
    ~Game();

    void getInput();

    bool isRunning();
    void setRunning(bool state);

    void refreshAllWindows();
    void refreshTopWindow();
    void pushWindow(WINDOW *win);
    WINDOW *popWindow();
    WINDOW *getTopWindow();
    int getStackSize();

  private:
    int mScore;

    bool mIsRunning;

    std::stack<WINDOW *> mWinStack;

    Point *mBoardSize;
    // Point *mScoreWindowSize;
    Point *mMenuWindowSize;

    Point *mBoardPos;
    // Point *mScoreWindowPos;
    Point *mMenuWindowPos;

    WINDOW *mBoardWindow;
    WINDOW *mScoreWindow;
    WINDOW *mMenuWindow;
};