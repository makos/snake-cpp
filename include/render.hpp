#pragma once
#include <curses.h>
#include <stack>
#include <string>

enum Color { Red = 1, Green, Yellow };

class Render {
  public:
    Render();
    ~Render();

    void print(int y, int x, std::string msg);
    void print(int y, int x, std::string msg, Color color);

    void pushWindow(int height, int width, int posy, int posx);
    void popWindow();

    void update();
    void clear();

    int getInput();

  private:
    WINDOW *topWindow();
    // WINDOW *mTopWindow;
    std::stack<WINDOW *> mWinStack;
};