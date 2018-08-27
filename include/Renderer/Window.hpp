/*
 * Window.hpp - high level wrapper over ncurses' WINDOW struct.
 */
#pragma once
#include <curses.h>
#include <memory>

class Window {
  public:
    Window(int height, int width, int posy, int posx);

    WINDOW *get();

    void setBox(bool state);
    int setDelay(bool state);
    int setKeypad(bool state);
    int refresh();
    int erase();
    int clear();
    int getKey();

  private:
    std::unique_ptr<WINDOW> mWindow;
    bool mBox;
};