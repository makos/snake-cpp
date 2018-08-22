#pragma once
#include <curses.h>
#include <string>

enum Color { Red = 1, Green, Yellow };

class Render {
  public:
    Render(int height, int width);
    ~Render();

    int kpad(bool state);

    void print(int y, int x, std::string msg);
    void print(int y, int x, std::string msg, Color color);

    void update();
    void clear();

    int getKey();

  private:
    // WINDOW *topWindow();
    WINDOW *mGameboard;
    // std::stack<WINDOW *> mWinStack;
};