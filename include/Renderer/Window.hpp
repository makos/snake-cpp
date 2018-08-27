/*
 * Window.hpp - high level wrapper over ncurses' WINDOW struct, providing
 * encapsulation of WINDOW related methods (in plain ncurses usually denoted
 * by w- prefix).
 */
#pragma once
#include "Renderer.hpp"
#include "Util/Point.hpp"
#include <curses.h>
#include <memory>
#include <string>

class Window {
  public:
    Window(int height, int width, int posy, int posx);

    WINDOW *get();

    void print(int y, int x, std::string msg);
    void print(int y, int x, std::string msg, Color color);
    void print(int y, int x, std::string msg, chtype attr);

    void setBox(bool state);
    int setDelay(bool state);
    int setKeypad(bool state);
    int refresh();
    int erase();
    int clear();
    int getKey();

    Point size();

  private:
    std::unique_ptr<WINDOW> mWindow;
    bool mBox;
};