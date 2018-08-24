#pragma once
#include <curses.h>
#include <memory>

class Window {
  public:
    Window(int height, int width, int posy, int posx);
    // ~Window();

    WINDOW *get();

    int setBox();
    int refresh();
    int erase();
    int clear();
    int getKey();

  private:
    // WINDOW *mWindow;
    std::unique_ptr<WINDOW> mWindow;
};