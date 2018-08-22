#pragma once

// #include <stack>
#include <map>

typedef struct _win WINDOW;
class Point;

class Game {
  public:
    Game();
    ~Game();

    // void getInput();

    bool isRunning();
    void setRunning(bool state);

    // void refreshWindow(std::string window);
    // WINDOW *getWindow(std::string window);

    // void refreshAllWindows();
    // void refreshTopWindow();
    // void pushWindow(WINDOW *win);
    // WINDOW *popWindow();
    // WINDOW *getTopWindow();
    // int getStackSize();

  private:
    int mScore;

    bool mIsRunning;

    // std::stack<WINDOW *> mWinStack;
    // std::map<std::string, WINDOW *> mWindows;

    // Point *mBoardSize;
    // Point *mScoreWindowSize;
    // Point *mMenuWindowSize;

    // Point *mBoardPos;
    // Point *mScoreWindowPos;
    // Point *mMenuWindowPos;

    // WINDOW *mBoardWindow;
    // WINDOW *mScoreWindow;
    // WINDOW *mMenuWindow;
};